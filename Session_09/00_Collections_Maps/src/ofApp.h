#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void draw();


    std::map<std::string, ofColor> myColors;
    
};
