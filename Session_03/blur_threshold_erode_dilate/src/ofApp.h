#pragma once


#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    ofVideoPlayer video;

    ofPixels binaryPixels;
    ofTexture binaryTexture;


    ofxPanel gui;
    ofParameter<int> blurLevel;
    ofParameter<bool> invert;
    ofParameter<int> erodeIterations;
    ofParameter<int> dilateIterations;
    ofParameter<int> threshold;

};

