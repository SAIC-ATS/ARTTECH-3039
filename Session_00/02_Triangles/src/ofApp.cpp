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

    // Don't fill the triangles.
    ofNoFill();

    // Find the center of the window.
    float centerX = ofGetWidth() / 2.0;
    float centerY = ofGetWidth() / 2.0;

    // Here We just repeat it with a for-loop to avoid copy-pasting code.

    for (int i = 0; i < 10; i++)
    {
        // Find the three corners of the triangle. In this case, we thing of
        // them as three points on a circle centered at centerX, centerY.

        float radius = 10 * i;

        float x0 = radius * std::cos(ofDegToRad(30)) + centerX;
        float y0 = radius * std::sin(ofDegToRad(30)) + centerY;

        float x1 = radius * std::cos(ofDegToRad(150)) + centerX;
        float y1 = radius * std::sin(ofDegToRad(150)) + centerY;

        float x2 = radius * std::cos(ofDegToRad(270)) + centerX;
        float y2 = radius * std::sin(ofDegToRad(270)) + centerY;

        ofDrawTriangle(x0, y0, x1, y1, x2, y2);
    }

}
