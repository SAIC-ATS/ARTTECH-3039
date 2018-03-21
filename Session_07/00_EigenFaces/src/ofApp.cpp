#include "ofApp.h"


void ofApp::setup()
{
    std::string dataPath = ofToDataPath("data.pca", true);
    
    if (ofFile(dataPath).exists())
    {
        ofLogNotice("ofApp::setup") << "Loading previous PCA results from: " << dataPath;
        cv::FileStorage fs(dataPath, cv::FileStorage::READ);
        pca.read(fs.root());
    }
    else
    {
        ofLogFatalError("ofApp::setup") << "Missing data.pca file.";
        ofExit();
    }

    // Initialize weights.
    weights = std::vector<float>(pca.eigenvectors.rows, 0.0);
    
}


void ofApp::update()
{
    if (recomputeImage)
    {
        // Start with a copy of the mean image.
        cv::Mat computedImage = pca.mean.reshape(imageNumChannels, imageHeight).clone();

        // Add the eigen vectors with the weights
        for (std::size_t i = 0; i < /*pca.eigenvectors.rows*/12; i++)
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


