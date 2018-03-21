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
    
    // The PCA data.
    cv::PCA pca;
    
    // A collection of all raw images.
    std::vector<cv::Mat> images;

    // The mean image we calculate.
    ofTexture meanTexture;
    
    // Computed image.
    ofTexture computedTexture;

    // Our for image combinations.
    std::vector<float> weights;
    bool recomputeImage = true;

    // The eigen images.
    std::vector<ofTexture> eigenTextures;

    // Image properties.
    std::size_t imageWidth = 0;
    std::size_t imageHeight = 0;
    std::size_t imageNumChannels = 0;
    ofPixelFormat imageFormat;
    
    bool noiseWalk = false;
    float noiseOffset = 0;
    
    enum
    {
        // The total number of eigen images we will calculate.
        MAX_PRINCIPAL_COMPONENTS = 0,
        
        MIN_WEIGHT = -127,
        MAX_WEIGHT = 127,
        SLIDER_HEIGHT = 24
    };
    
};
