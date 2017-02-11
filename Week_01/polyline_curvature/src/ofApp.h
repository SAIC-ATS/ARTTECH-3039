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

    std::vector<Circle> circles;
    std::vector<glm::vec2> points;

    bool isRecording = false;;
    
};
