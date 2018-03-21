#pragma once


#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;

    void loadTexture(const cv::Mat& mat, ofTexture& tex);
    
    // The image we want to encode.
    cv::Mat imageToEncode;

    // The texture of the image to encode.
    ofTexture imageToEncodeTexture;

    // The PCA data.
    cv::PCA pca;
    
    // Computed image.
    ofTexture computedTexture;

    // Our for image combinations.
    std::vector<float> weights;
    bool recomputeImage = true;

    // The number of PCA components we will use to encode.
    int numComponentsToEncode = 0;

};
