#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;

    void addPoint(int x, int y);
    
    ofPolyline poly;
    ofPolyline resampledPoly;
    ofPath path;
    
    ofImage image;

};
