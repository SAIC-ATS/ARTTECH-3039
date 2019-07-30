#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::draw()
{
    float width = ofGetWidth();
    float height = ofGetHeight();
    float mouseX = ofGetMouseX();

    float size = ofMap(mouseX, 0, width, 5, 100, true);

    for (float x = 0; x < width; x += size)
    {
        for (float y = 0; y < height; y += size)
        {
            float hue = ofMap(x, 0, width, 0, 255);
            float saturation = ofMap(y, 0, height, 0, 255);

            ofColor color = ofColor::fromHsb(hue, saturation, 255);
            ofSetColor(color);
            ofDrawRectangle(x, y, size, size);
        }
    }
}

