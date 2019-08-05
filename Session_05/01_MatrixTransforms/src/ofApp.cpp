#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    ofLoadImage(texture, "puppy.jpg");
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateZDeg(45);
    
    ofDrawCircle(0, 0, 5);
    
    ofSetColor(ofColor::green);
    ofDrawCircle(-100, -100, 10);
    
    ofSetColor(255);
    texture.draw(0, 0);
    
    ofPopMatrix();

    texture.draw(0, 0);
}
