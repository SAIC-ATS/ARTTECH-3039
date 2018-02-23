#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    ofPolyline polyline;

    ofxBox2d box2d;

    std::vector<std::shared_ptr<ofxBox2dCircle>> circles;
    std::vector<std::shared_ptr<ofxBox2dRect>> rectangles;
    std::vector<std::shared_ptr<ofxBox2dPolygon>> polys;

    ofTexture tex;

};
