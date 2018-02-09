#pragma once


#include "ofMain.h"
#include "ofxARTTECH3039.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;

    ofPolyline poly;

    ofPolyline resampledPoly;
    std::vector<float> curvatures;

};
