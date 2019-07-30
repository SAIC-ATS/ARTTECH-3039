#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::draw()
{
    for (float x = 0; x < ofGetWidth(); x += 100)
    {
        for (float y = 0; y < ofGetHeight(); y+= 100)
        {
            ofDrawCircle(x, y, 5);
        }
    }
}
