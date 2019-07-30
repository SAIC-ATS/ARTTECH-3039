#include "ofApp.h"


void ofApp::setup()
{
    // This setup() function runs once at the beginning of the program.

    // Set the size of the window.
    ofSetWindowShape(400, 400);

    // Set the background color (dark gray).
    ofBackground(80);
}

    
void ofApp::draw()
{
    // The draw() function will be called each time the screen is refreshed
    // (usually 60 frames / second).

    // Set the draw color to white.
    ofSetColor(255);

    float numVertLines = 50;
    float numHorzLines = 50;

    float width = ofGetWidth();
    float height = ofGetHeight();

    // First draw the vertical lines.
    for (int i = 0; i < numVertLines; i++)
    {
        float x = i * width / numVertLines;
        ofDrawLine(x, 0, x, ofGetHeight());
    }

    // Second, draw the horizontal lines.
    for (int i = 0; i < numHorzLines; i++)
    {
        float y = i * height / numHorzLines;
        ofDrawLine(0, y, ofGetWidth(), y);
    }

}
