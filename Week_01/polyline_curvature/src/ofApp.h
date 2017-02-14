#pragma once


#include "ofMain.h"
#include "Circle.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);

    void addPoint(float x, float y);

    std::vector<Circle> circles;
    ofPolyline polyline;

    bool isRecording = false;;
    
};
