#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::draw()
{
    float width = ofGetWidth();
    float height = ofGetHeight();
    
    float halfWidth = ofGetWidth() / 2.0;
    float halfHeight = ofGetHeight() / 2.0;

    float mouseX = ofGetMouseX();
    float mouseY = ofGetMouseY();
    
    if (mouseX > halfWidth)
    {
        if (mouseY > halfHeight)
        {
            ofSetColor(ofColor::yellow);
            ofDrawRectangle(halfWidth, halfHeight, halfWidth, halfHeight);
        }
        else
        {
            ofSetColor(ofColor::red);
            ofDrawRectangle(halfWidth, 0, halfWidth, halfHeight);
        }
    }
    else
    {
        if (mouseY > halfHeight)
        {
            ofSetColor(ofColor::blue);
            ofDrawRectangle(0, halfHeight, halfWidth, halfHeight);
        }
        else
        {
            ofSetColor(ofColor::green);
            ofDrawRectangle(0, 0, halfWidth, halfHeight);
        }
    }
}
