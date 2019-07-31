#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;

    ofVideoGrabber grabber;
    // ofVideoPlayer player;

    ofPixels myPixels;
  
    std::size_t brightestX = 0;
    std::size_t brightestY = 0;
    
};
