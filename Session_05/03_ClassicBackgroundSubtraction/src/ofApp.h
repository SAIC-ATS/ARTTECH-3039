#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;

    ofVideoGrabber grabber;
    
    ofPixels backgroundPixels;
    ofPixels foregroundPixels;
    ofPixels binaryPixels;
    
    ofTexture backgroundTexture;
    ofTexture foregroundTexture;
    ofTexture binaryTexture;
    
    ofTexture maskedTexture;

    
    int binaryThreshold = 127;
    
};
