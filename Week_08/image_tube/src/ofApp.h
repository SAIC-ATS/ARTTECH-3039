#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void mouseReleased(int x, int y, int button) override;

    ofImage image;

    float yRotationAngleDeg = 0;
    float yRotationAngularVelocity = 0.0;

};
