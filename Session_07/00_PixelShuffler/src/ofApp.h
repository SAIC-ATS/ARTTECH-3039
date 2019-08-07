#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;

    ofPixels makeRainbowPixels(std::size_t width, std::size_t height);
    
    
    ofPixels rainbowPixels;
    ofTexture rainbowTexture;

    ofPixels shuffledRainbowPixels;
    ofTexture shuffledRainbowTexture;

    std::vector<float> rowOffsets;
    std::vector<float> rowVelocities;

};
