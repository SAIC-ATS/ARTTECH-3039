#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofPixels pixels;
    ofTexture texture;
    
    ofMesh mesh;
    
    ofEasyCam cam;
};
