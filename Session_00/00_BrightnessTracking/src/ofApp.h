#pragma once


#include "ofMain.h"


class ofApp : public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    // Our video grabber.
    ofVideoGrabber grabber;

    // To keep track of the pixel index x with the brightest value.
    std::size_t xPosition = 0;

    // To keep track of the pixel index y with the brightest value.
    std::size_t yPosition = 0;

    // A polyline to keep track of the tracking history.
    ofPolyline polyline;

};
