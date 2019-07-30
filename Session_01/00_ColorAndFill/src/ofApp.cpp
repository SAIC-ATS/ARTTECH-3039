#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);

    // Brightness form: 80
    // RGB form: 80, 80, 80
    // RGBA form: 80, 80, 80, 80
    // Brightness and alpha form: 80, 80
    
}


void ofApp::draw()
{
    ofNoFill();
    ofSetColor(255, 127);
    ofDrawRectangle(0, 0, 100, 100);
    
    ofFill();
    ofSetColor(255, 0, 0, 127);
    ofDrawRectangle(50, 50, 100, 100);
    
    ofNoFill();
    ofSetColor(0, 0, 255, 127);
    ofDrawRectangle(100, 100, 100, 100);
    
    ofColor mySpecialRed = ofColor(255, 30, 22, 200);
    ofColor mySpecialGreen = ofColor(10, 255, 22, 200);

    ofFill();
    ofSetColor(mySpecialRed);
    ofDrawCircle(200, 200, 100);
    
    ofFill();
    ofSetColor(mySpecialGreen);
    ofDrawCircle(400, 400, 100);

    
    ofFill();
    ofSetColor(ofColor::mediumSeaGreen);
    ofDrawCircle(600, 600, 100);

    ofColor myHSBColor = ofColor::fromHsb(180, 127, 255);
    
    ofFill();
    ofSetColor(myHSBColor);
    ofDrawCircle(650, 650, 100);
    
    ofColor myHexColor = ofColor::fromHex(0xFF0000);
    
    ofFill();
    ofSetColor(myHexColor);
    ofDrawCircle(700, 700, 100);    
}
