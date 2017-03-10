#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    std::map<int, std::vector<std::string>> myMap;

};
