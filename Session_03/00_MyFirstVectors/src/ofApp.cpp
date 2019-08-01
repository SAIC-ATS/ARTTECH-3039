#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    myPosition.x = ofGetWidth() / 2.0f;
    myPosition.y = ofGetHeight() / 2.0f;
    myVelocity = { -10, 10 };
}


void ofApp::update()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    
    // myPosition.x = myPosition.x + myVelocity.x;
    // myPosition.y = myPosition.y + myVelocity.y;
    myPosition += myVelocity;
    
    if (myPosition.x > w)
    {
        myPosition.x = 0;
    }
    
    if (myPosition.x < 0)
    {
        myPosition.x = w;
    }
    
    if (myPosition.y > h)
    {
        myPosition.y = 0;
    }

    if (myPosition.y < 0)
    {
        myPosition.y = h;
    }

}


void ofApp::draw()
{
    ofDrawCircle(myPosition, 40);
}

