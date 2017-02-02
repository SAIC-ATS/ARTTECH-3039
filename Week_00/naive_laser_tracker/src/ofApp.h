#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    ofVideoGrabber grabber;

    // To keep track of the pixel index x with the brightest value.
    std::size_t maxX = 0;

    // To keep track of the pixel index y with the brightest value.
    std::size_t maxY = 0;

    // A polyline to keep track of the tracking history.
    ofPolyline polyline;

};
