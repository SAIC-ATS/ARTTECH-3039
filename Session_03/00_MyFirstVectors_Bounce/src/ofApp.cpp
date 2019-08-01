#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    myPosition.x = ofGetWidth() / 2.0f;
    myPosition.y = ofGetHeight() / 2.0f;
    myVelocity = { -10, 10 };
    
    myGravity = { 0, 0.8 };
}


void ofApp::update()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    
    // myPosition.x = myPosition.x + myVelocity.x;
    // myPosition.y = myPosition.y + myVelocity.y;
    myPosition += myVelocity;

    // Add a litte acceleration / gravity to the velocity.
    myVelocity += myGravity;
    
    // Drag.
    myVelocity *= 0.99;
    
    // Right wall.
    if (myPosition.x + radius > w)
    {
        myPosition.x = w - radius;
        myVelocity.x *= -0.5;
    }
    
    // Left
    if (myPosition.x - radius < 0)
    {
        myPosition.x = radius;
        myVelocity.x *= -0.5;
    }
    
    if (myPosition.y + radius > h)
    {
        myPosition.y = h - radius;
        myVelocity.y *= -0.5;
    }

    if (myPosition.y - radius < 0)
    {
        myPosition.y = radius;
        myVelocity.y *= -0.5;
    }

}


void ofApp::draw()
{
    ofDrawCircle(myPosition, radius);
}

