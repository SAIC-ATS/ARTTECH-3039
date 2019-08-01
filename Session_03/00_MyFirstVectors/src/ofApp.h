#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    glm::vec2 myPosition;
    glm::vec2 myVelocity;
    
    
};
