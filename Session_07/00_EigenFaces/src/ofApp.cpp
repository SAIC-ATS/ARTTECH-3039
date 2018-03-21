#include "ofApp.h"


void ofApp::setup()
{
    // Load all jpg images.
    ofDirectory dir("images/");
    dir.allowExt("jpg");
    
    // Image num channels.
    imageNumChannels = 3;
    
    for (auto& file: dir)
    {
        ofPixels pix;
        if (ofLoadImage(pix, file))
        {
            if (imageWidth == 0 && imageHeight == 0)
            {
                imageWidth = pix.getWidth();
                imageHeight = pix.getHeight();
                imageFormat = pix.getPixelFormat();
            }
            else if (imageWidth != pix.getWidth()
                  || imageHeight != pix.getHeight()
                  || pix.getNumChannels() != imageNumChannels
                  || pix.getPixelFormat() != imageFormat)
            {
                ofLogError("ofApp::setup") << "The first image was: " << imageWidth << " x " << imageHeight << "x" << imageNumChannels << " but this image was " << pix.getWidth() << " x " << pix.getHeight() << "x" << pix.getNumChannels() << ": " << file.getAbsolutePath();
                ofExit();
            }
            
            // Save a copy of this image.
            cv::Mat img;
            ofxCv::copy(pix, img);
            img.convertTo(img, CV_32FC3, 1.0 / 255.0);
            images.push_back(img);
            
            // If we want to augment our data, we might mirror the image
            // horizontally to create another data point like this:
             cv::Mat imgFlip;
             cv::flip(img, imgFlip, 1);
             images.push_back(imgFlip);
        }
        else
        {
            ofLogError("ofApp::setup") << "Unable to load image: " << file.getAbsolutePath() << ", skipping.";
        }
    }
    
    // Double check data integrity.
    if (images.empty())
    {
        ofLogError("ofApp::setup") << "No images were loaded from " << dir.getAbsolutePath() << ", quitting.";
        ofExit();
    }
    else
    {
        ofLogNotice("ofApp::setup") << "Loaded " << images.size() << " images of size " << imageWidth << " x " << imageHeight;
    }
    
    // Create one giant data matrix containing all data.
    // The data matrix will be a 2-D matrix with
    //
    //      new_width == width * height * numChannels
    //      new_height == images.size()
    //
    cv::Mat data(images.size(), imageWidth * imageHeight * imageNumChannels, CV_32F);
    
    // Turn an image into one row vector in the data matrix
    for (std::size_t i = 0; i < images.size(); ++i)
    {
        // Reshape the `image` as a 1-D matrix.
        cv::Mat reshaped = images[i].reshape(1, 1);
        
        // Copy the 1-D vector into the data cv::Mat.
        reshaped.copyTo(data.row(i));
    }
    
    std::string dataPath = ofToDataPath("data.pca", true);
    
    if (ofFile(dataPath).exists())
    {
        ofLogNotice("ofApp::setup") << "Loading previous PCA results from: " << dataPath;
        cv::FileStorage fs(dataPath, cv::FileStorage::READ);
        pca.read(fs.root());
    }

    // Did it load from disk?
    if (pca.eigenvalues.empty())
    {
        ofLogNotice("ofApp::setup") << "Calculating PCA, this might take a while.";
        pca(data,  // This is the data vector we calculated above.
            cv::Mat(), // We don't have a pre-computed mean, so we will let the algorithm calculate it for us.
            cv::PCA::DATA_AS_ROW, // Intrepret the data as having each sample in a row (like our data above).
            MAX_PRINCIPAL_COMPONENTS // The maximum principal components we want to keep.
            );
        
        // Save the results.
        cv::FileStorage fs(dataPath, cv::FileStorage::WRITE);
        pca.write(fs);
        fs.release();
    }
    
    // Extract mean vector and reshape it to obtain mean image.'
    loadTexture(pca.mean.reshape(imageNumChannels, imageHeight), meanTexture);

    // Iterate through the eigen images and save each to its own image.
    for(std::size_t i = 0; i < pca.eigenvectors.rows; i++)
    {
        // Load textures.
        eigenTextures.push_back(ofTexture());

        loadTexture(pca.eigenvectors.row(i).reshape(imageNumChannels, imageHeight),
                    eigenTextures.back());
        
        // Add the weights.
        weights.push_back(0);
    }
}


void ofApp::update()
{
    if (noiseWalk)
    {
        noiseOffset += 0.01;
        int i = 0;
        for (auto& w: weights)
            w = ofMap(ofNoise(noiseOffset + (i++)), 0, 1, MIN_WEIGHT, MAX_WEIGHT);
        recomputeImage = true;
    }
    
    
    if (recomputeImage)
    {
        // Start with a copy of the mean image.
        cv::Mat computedImage = pca.mean.reshape(imageNumChannels, imageHeight).clone();

        // Add the eigen vectors with the weights
        for (std::size_t i = 0; i < pca.eigenvectors.rows; i++)
        {
            computedImage += (pca.eigenvectors.row(i).reshape(imageNumChannels, imageHeight) * weights[i]);
        }

        loadTexture(computedImage, computedTexture);

        recomputeImage = false;
    }
}


void ofApp::draw()
{
    ofSetColor(255);
    
    float scaleX = 3;
    float scaleY = 3;
    ofPushMatrix();
    ofScale(scaleX, scaleY, 1);
    computedTexture.draw(0, 0);
    ofPopMatrix();

    ofDrawBitmapStringHighlight("Computed Image", 14, 20);

    // Draw the Grid.
    float width = meanTexture.getWidth();
    float height = meanTexture.getHeight();
    
    float xOffset = width * scaleX;
    float x = xOffset;
    float y = 0;
    
    for (std::size_t i = 0; i < eigenTextures.size(); ++i)
    {
        ofSetColor(255);
        eigenTextures[i].draw(x, y);

        ofRectangle sliderRect(x, y + height - SLIDER_HEIGHT, width, SLIDER_HEIGHT);

        bool isOverSlider = sliderRect.inside(ofGetMouseX(), ofGetMouseY());
        
        // If the mouse is pressed, do things.
        if (isOverSlider && ofGetMousePressed())
        {
            // If we are over the current image, adjust its weight.
            weights[i] = ofMap(ofGetMouseX(), x, x + width, MIN_WEIGHT, MAX_WEIGHT, true);
            recomputeImage = true;
        }
        
        if (isOverSlider)
            ofSetColor(255, 255, 0, 127);
        else
            ofSetColor(255, 0, 0, 127);
        
        ofDrawRectangle(sliderRect.x,
                        sliderRect.y,
                        ofMap(weights[i], MIN_WEIGHT, MAX_WEIGHT, 0, sliderRect.width, true),
                        sliderRect.height);
        
        ofSetColor(255);
        ofDrawBitmapString("PC: " + ofToString(i) + " " + ofToString(weights[i]), sliderRect.x + 5, sliderRect.y + 16);

        // Figure out the placement of the next image.
        if (x + (2 * width) > ofGetWidth())
        {
            y += height;
            x = xOffset;
        }
        else x += width;
    }
}


void ofApp::keyPressed(int key)
{
    if (key == 'r')
    {
        for (auto& w: weights) w = 0;
        recomputeImage = true;
    }
    else if (key == 'n')
    {
        noiseWalk = !noiseWalk;
    }
}


void ofApp::loadTexture(const cv::Mat& mat, ofTexture& tex)
{
    ofFloatPixels pix;
    ofxCv::copy(mat, pix);
    
    // The eigen vectors are not particularly easy to visualize because the
    // numbers are extreme and outside of the normal 0-1 range for
    // ofFloatPixels. Therefore, we can normalize the values.
    cv::normalize(ofxCv::toCv(pix), // Source image.
                  ofxCv::toCv(pix), // Destination image.
                  0, // Min value.
                  1, // Max avalue.
                  cv::NORM_MINMAX, // Method for normalization.
                  ofxCv::getCvImageType(imageNumChannels, CV_32F) // The target image type.
                  );
    
    tex.loadData(pix);
}


