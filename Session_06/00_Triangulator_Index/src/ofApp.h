#pragma once

#include "ofMain.h"
#include "ofxARTTECH3039.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void mousePressed(int x, int y, int button);

    std::vector<glm::vec2> points;
    bool needsCalculation = true;

    ofMesh mesh;

};
