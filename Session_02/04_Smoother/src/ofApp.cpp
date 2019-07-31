#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::update()
{
/////
    noisyMouseX = ofGetMouseX();
    noisyMouseY = ofGetMouseY();
    noisyMouseX += ofRandom(-40, 40);
    noisyMouseY += ofRandom(-40, 40);
////
    
    smoothMouseX = smoothingFactor * smoothMouseX + (1 - smoothingFactor) * noisyMouseX;
    smoothMouseY = smoothingFactor * smoothMouseY + (1 - smoothingFactor) * noisyMouseY;
}


void ofApp::draw()
{
    ofFill();
    ofSetColor(ofColor::yellow);
    ofDrawCircle(noisyMouseX, noisyMouseY, 20);

    ofNoFill();
    ofSetColor(ofColor::white);
    ofDrawCircle(smoothMouseX, smoothMouseY, 30);

    
}
