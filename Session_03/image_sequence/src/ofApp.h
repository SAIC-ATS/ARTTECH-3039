#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofVideoGrabber camera;
    bool isRecording = false;

    std::vector<ofPixels> frames;

};

