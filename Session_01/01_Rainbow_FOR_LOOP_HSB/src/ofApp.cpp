#include "ofApp.h"


void ofApp::setup()
{
    ofSetWindowShape(400, 400);   
}


void ofApp::draw()
{
    // for (start condition; logical end condition; increment)
    // {
    // }

    // i is the increment / index variable.
    // i < 7
    //
    // 0, 1, 2, 3, 4, 5, 6 ...

    float numColors = 25;
    
    float rectangleWidth = ofGetWidth() / numColors;

    for (int i = 0; i < numColors; i++)
    {
        float hue = ofMap(i, 0, numColors, 0, 255);
        ofColor color = ofColor::fromHsb(hue, 255, 255, 127);
        ofSetColor(color);
        ofDrawRectangle(i * rectangleWidth, 0, rectangleWidth, ofGetHeight());
    }
    
    ofColor red = ofColor(255, 0, 0);
    
    ofColor transparentRed = ofColor(red, 127);
    ofColor transparentViolet = ofColor(ofColor::violet, 127);

    // Access color channels individually.
    transparentRed.r = 75;
    transparentRed.a = 75;
}
