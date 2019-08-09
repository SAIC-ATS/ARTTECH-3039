#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
    void setup() override;
    void draw() override;

    void mousePressed(int x, int y, int button) override;

    std::vector<glm::vec3> vertices;
    std::vector<ofFloatColor> colors;

    ofMesh mesh;

    ofEasyCam cam;
};
