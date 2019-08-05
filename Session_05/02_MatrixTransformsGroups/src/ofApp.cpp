#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::update()
{
    angleDegrees0 += 1;
    angleDegrees1 += 0.5;
    angleDegrees2 += 0.25;
}


void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateZDeg(angleDegrees0);

    // Horizontal line, of length 100.
    ofSetColor(ofColor::green);
    ofDrawLine(0, 0, 100, 0);
    
    ofPushMatrix();
    ofTranslate(100, 0);
    ofRotateZDeg(angleDegrees1);
    ofSetColor(ofColor::yellow);
    ofDrawLine(0, 0, 100, 0);
    
    ofPushMatrix();
    ofTranslate(100, 0);
    ofRotateZDeg(angleDegrees2);
    ofSetColor(ofColor::blue);
    ofDrawLine(0, 0, 100, 0);


    ofPopMatrix();
    ofPopMatrix();
    ofPopMatrix();
}

