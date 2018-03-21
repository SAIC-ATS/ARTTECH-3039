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

    void dragEvent(ofDragInfo dragInfo) override;
    void loadTargetImage(const std::string& file);
    void loadTexture(const cv::Mat& mat, ofTexture& tex);
    
    // The PCA data.
    cv::PCA pca;
    
    // Computed image.
    ofTexture computedTexture;

    // Our for image combinations.
    std::vector<float> weights;
    bool recomputeImage = true;

    // Image properties.
    std::size_t imageWidth = 0;
    std::size_t imageHeight = 0;
    std::size_t imageNumChannels = 0;
    ofPixelFormat imageFormat;
    
};
