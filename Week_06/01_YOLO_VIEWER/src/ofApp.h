#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    // The current image index.
    std::size_t imageIndex = 0;

    // This is the current image that we are viewing.
    ofImage currentImage;

    // A mapping from the image path, to its json data.
    std::vector<std::pair<std::string, ofJson>> data;

};
