#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void draw();
    void mouseDragged(int x, int y, int button);

    ofPolyline line;

};
