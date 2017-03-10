#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    std::vector<int> myVector;

    std::set<int> mySet;

    std::map<std::string, int> myMap;

    std::map<std::string, std::vector<int> /*, std::greater<std::string> */> myMapOfVectors;

};
