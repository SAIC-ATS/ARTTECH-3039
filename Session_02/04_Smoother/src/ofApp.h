#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    float noisyMouseX = 0;
    float noisyMouseY = 0;

    float smoothMouseX = 0;
    float smoothMouseY = 0;

    // A value that goes between 0 and 1.
    // 1 is totally smooth (not moving).
    // 0 is totally noisy.
    float smoothingFactor = 0.99;
    
};
