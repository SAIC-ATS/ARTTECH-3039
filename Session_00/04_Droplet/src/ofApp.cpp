#include "ofApp.h"


void ofApp::setup()
{
    // This setup() function runs once at the beginning of the program.

    // Set the size of the window.
    ofSetWindowShape(400, 720);

    // Set the background color (dark gray).
    ofBackground(80);
}

    
void ofApp::draw()
{
    // The draw() function will be called each time the screen is refreshed
    // (usually 60 frames / second).

    // Set the draw color to white.
    ofSetColor(255);
    ofFill();

    float dropTopX = ofGetWidth() / 2.0;
    float dropTopY = ofGetHeight() / 6.0;

    float dropWidth = ofGetWidth() * 2.0 / 3.0;

    float dropSideY = ofGetHeight() * 0.5;
    float dropSideLeftX = ofGetWidth() / 3.0;
    float dropSideRightX = ofGetWidth() * 2.0 / 3.0;

    float dY = dropTopY - dropSideY;
    float dXLeft = dropTopX - dropSideLeftX;
    float dXRight = dropTopX - dropSideRightX;

    float lengthRight = std::sqrt(dY * dY + dXRight * dXRight);
    float lengthLeft = std::sqrt(dY * dY + dXLeft * dXLeft);

    // Map the length of the bezier control handles to the mouse y position.
    float bezierHandleDistance = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, -400);

    float bezierHandleLeftX = bezierHandleDistance * (dXLeft / lengthLeft) + dropSideLeftX;
    float bezierHandleLeftY = bezierHandleDistance * (dY / lengthLeft) + dropSideY;

    float bezierHandleRightX = bezierHandleDistance * (dXRight / lengthRight) + dropSideRightX;
    float bezierHandleRightY = bezierHandleDistance * (dY / lengthRight) + dropSideY;

    // This makes our bezier look smoother.
    ofSetCurveResolution(128);

    ofBeginShape();
    ofVertex(dropTopX, dropTopY);
    ofVertex(dropSideLeftX, dropSideY);

    ofBezierVertex(bezierHandleLeftX,
                   bezierHandleLeftY,
                   bezierHandleRightX,
                   bezierHandleRightY,
                   dropSideRightX,
                   dropSideY);

    ofVertex(dropSideRightX, dropSideY);

    ofEndShape();

    // Draw the bezier handles to demo.
    ofNoFill();
    ofSetColor(40);
    ofDrawLine(dropSideLeftX,
               dropSideY,
               bezierHandleLeftX,
               bezierHandleLeftY);
    ofDrawCircle(bezierHandleLeftX, bezierHandleLeftY, 5);

    ofDrawLine(dropSideRightX,
               dropSideY,
               bezierHandleRightX,
               bezierHandleRightY);
    ofDrawCircle(bezierHandleRightX, bezierHandleRightY, 5);

}
