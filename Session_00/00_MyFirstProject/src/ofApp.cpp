#include "ofApp.h"


void ofApp::setup()
{
    // This setup() function runs once at the beginning of the program.

    // Set the size of the window.
    ofSetWindowShape(100, 100);

    // Set the background color (dark gray).
    ofBackground(80);
}

    
void ofApp::draw()
{
    // The draw() function will be called each time the screen is refreshed
    // (usually 60 frames / second).

    // Upper left
    ofDrawRectangle(0, 0, 25, 25);

    // Upper right
    ofDrawRectangle(100 - 25, 0, 25, 25);

    // lower right
    ofDrawRectangle(100 - 25, 100 - 25, 25, 25);

    // Lower left
    ofDrawRectangle(0, 100 - 25, 25, 25);

    // Lower left
    ofDrawRectangle(100 / 2 - 25 / 2, 100 / 2 - 25 / 2, 25, 25);

}
