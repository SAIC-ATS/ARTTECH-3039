#pragma once

#include "ofMain.h"
#include "ofxARTTECH3039.h"


class ofApp : public ofBaseApp{

public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;
    void mousePressed(int x, int y, int button) override;

    std::vector<glm::vec2> points;
    std::vector<Circle> circles;

    ofMesh mesh;

    // Voronoi
    std::vector<ofPath> vFacets;
    std::vector<glm::vec2> vCenters;

    bool needsCalculation = true;


};
