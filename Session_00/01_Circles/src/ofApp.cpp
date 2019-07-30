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

    // Make a finer circle resolution.
    ofSetCircleResolution(64);

    // Set the draw color to white.
    ofSetColor(255);

    // Don't fill the circles.
    ofNoFill();

    // Find the center of the window.
    float centerX = ofGetWidth() / 2.0;
    float centerY = ofGetWidth() / 2.0;

    // Draw 10 concentric circles.
    ofDrawCircle(centerX, centerY, 10);
    ofDrawCircle(centerX, centerY, 20);
    ofDrawCircle(centerX, centerY, 30);
    ofDrawCircle(centerX, centerY, 40);
    ofDrawCircle(centerX, centerY, 50);
    ofDrawCircle(centerX, centerY, 60);
    ofDrawCircle(centerX, centerY, 70);
    ofDrawCircle(centerX, centerY, 80);
    ofDrawCircle(centerX, centerY, 90);
    ofDrawCircle(centerX, centerY, 100);

}
