#include "ofApp.h"


void ofApp::setup()
{
    ofSetWindowShape(400, 400);
}


void ofApp::draw()
{
    // All the colors of a rainbow in a vector.
    std::vector<ofColor> colors = {
        ofColor::red,
        ofColor::orange,
        ofColor::yellow,
        ofColor::green,
        ofColor::blue,
        ofColor::indigo,
        ofColor::violet
    };
    
    // Calculate the width / height of the drawing.
    float width = ofGetWidth();
    float height = ofGetWidth();
    float rectangleWidth = width / colors.size();

    for (int i = 0; i < colors.size(); i++)
    {
        ofSetColor(colors[i]);
        ofDrawRectangle(i * rectangleWidth, 0, rectangleWidth, height);
    }
}
