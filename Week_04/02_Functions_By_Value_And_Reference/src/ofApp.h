#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void myFuncPassedByValue(int i);

    void myFuncPassedByReference(int& i);

    // we use int here for demonstration, but you don't need const
    // references for non-class data datatypes.
    void myFuncPassedByConstReference(const int& i);

};
