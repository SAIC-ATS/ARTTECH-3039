#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    float angleDegrees0 = 0;
    float angleDegrees1 = 0;
    float angleDegrees2 = 0;
    
};
