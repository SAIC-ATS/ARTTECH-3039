#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;
    
    ofPixels myPixels;
    ofTexture puppyTexture;
    float fearFactor = 0.0f;
};
