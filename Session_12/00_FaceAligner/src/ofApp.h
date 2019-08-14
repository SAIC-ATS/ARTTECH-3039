#pragma once


#include "ofMain.h"
#include "ofxDlib.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    // A map of all of our pixels for each folder.
    std::map<std::string, std::vector<ofPixels>> pixelMap;

    // The aligned versions of the faces found in the pixelMap above.
    std::map<std::string, std::vector<ofPixels>> faceChipsMap;

};
