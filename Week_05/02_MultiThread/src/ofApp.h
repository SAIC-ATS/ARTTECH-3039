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

    std::vector<std::shared_ptr<MyClass>> myClasses;

    int brightness = 0;

};
