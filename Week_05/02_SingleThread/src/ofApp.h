#pragma once


#include "ofMain.h"
#include "MyClass.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void exit();

    MyClass myClass;

    int brightness = 0;

};
