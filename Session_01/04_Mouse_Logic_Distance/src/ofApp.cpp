#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::draw()
{
    float width = ofGetWidth();
    float height = ofGetHeight();
    
    float mouseX = ofGetMouseX();
    float mouseY = ofGetMouseY();
    
    bool isMousePressed = ofGetMousePressed();
    
    float size = 40;
    
    // Max ditance between two points (in this case the diagonal corners).
    float maxDistance = std::sqrt(width * width + height * height);
    
    for (float x = 0; x < width; x += size)
    {
        for (float y = 0; y < height; y += size)
        {
            // float r = std::sqrt((x - mouseX) * (x - mouseX) + (y - mouseY) * (y - mouseY));
            float distance = ofDist(x, y, mouseX, mouseY);
            float circleSize = ofMap(distance, 0, maxDistance, 50, 5, true);
            float hue = ofMap(distance, 0, maxDistance, 0, 255, true);
            ofColor color = ofColor::fromHsb(hue, 255, 255, 50);
            ofSetColor(color);
            
            if (isMousePressed)
            {
                // ofSetRectMode(OF_RECTMODE_CENTER);
                ofDrawRectangle(x, y, circleSize, circleSize);
                // ofDrawEllipse(x, y, circleSize, circleSize * 2);
            }
            else
            {
                ofDrawCircle(x, y, circleSize);
            }
        }
    }
}

