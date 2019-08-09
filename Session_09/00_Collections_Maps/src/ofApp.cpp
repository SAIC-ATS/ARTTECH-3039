#include "ofApp.h"

void ofApp::setup()
{
    myColors["beautiful blue"] = ofColor(0, 2, 244);
    myColors["life giving yellow"] = ofColor(255, 255, 0);
}

void ofApp::draw()
{
    ofSetColor(myColors["beautiful blue"]);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());


    ofSetColor(myColors["life giving yellow"]);
    ofDrawRectangle(100, 100, 100, 100);
    
    // This doesn't exist so it makes a default entry (which is a white color).
    ofSetColor(myColors["just some random thing"]);
    ofDrawRectangle(200, 200, 100, 100);
}
