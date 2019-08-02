#pragma once


#include "ofMain.h"
#include "ofxCv.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofVideoGrabber grabber;
    ofxCv::ObjectFinder finder;
    
};
