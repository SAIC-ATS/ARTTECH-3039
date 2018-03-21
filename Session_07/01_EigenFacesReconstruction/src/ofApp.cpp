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

    // Load the image to encode.
    ofPixels pix;
    ofLoadImage(pix, "me.jpg");

    // Copy the image into a texture.
    imageToEncodeTexture.loadData(pix);

    // Copy oF image to a CV image.
    ofxCv::copy(pix, imageToEncode);

    // Convert the CV image to a floating poing version of the image.
    // Everything is now in the range 0 - 1.
    imageToEncode.convertTo(imageToEncode, CV_32FC3, 1 / 255.0);

    // This makes it a long row 1-D matrix.
    imageToEncode = imageToEncode.reshape(1, 1);

    // Subtract the mean vector from the image to encode.
    imageToEncode -= pca.mean;

}


void ofApp::update()
{

    if (recomputeImage)
    {
        cv::Mat encodedImage = pca.mean.clone();

        for (int i = 0; i < numComponentsToEncode; i++)
        {
            cv::Mat eigenImage = pca.eigenvectors.row(i);

            double weight = imageToEncode.dot(eigenImage);

            encodedImage = encodedImage + weight * eigenImage;
        }

        loadTexture(encodedImage.reshape(3, imageToEncodeTexture.getHeight()), computedTexture);

        recomputeImage = false;
    }
}


void ofApp::draw()
{
    ofPushMatrix();
    ofScale(3, 3, 1);

    imageToEncodeTexture.draw(0, 0);
    computedTexture.draw(imageToEncodeTexture.getWidth(), 0);

    std::stringstream s;
    s << numComponentsToEncode << " / " << pca.eigenvectors.size[0] << " components used.";

    ofPopMatrix();

    ofDrawBitmapStringHighlight(s.str(), 20, 20);

}


void ofApp::keyPressed(int key)
{
    if (key == '-')
    {
        numComponentsToEncode = std::max(numComponentsToEncode - 1, 0);
        recomputeImage = true;
    }
    else if (key == '=')
    {
        numComponentsToEncode = std::min(numComponentsToEncode + 1, pca.eigenvectors.size[0]);
        recomputeImage = true;
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
                  ofxCv::getCvImageType(3, CV_32F) // The target image type.
                  );
    
    tex.loadData(pix);
}


