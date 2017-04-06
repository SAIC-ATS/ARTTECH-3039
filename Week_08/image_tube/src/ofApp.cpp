#include "ofApp.h"


void ofApp::setup()
{
    image.load("puppy.jpg");
    ofEnableDepthTest();
}


void ofApp::update()
{
    yRotationAngleDeg += yRotationAngularVelocity;

    yRotationAngularVelocity *= 0.95;

    if (yRotationAngularVelocity < 0)
    {
        yRotationAngularVelocity = 0;
    }
}


void ofApp::draw()
{
    float cylinderX = ofGetWidth() / 2;
    float cylinderY = ofGetHeight() / 4;
    float cylinderHeight = 2 * ofGetHeight() / 4;
    float cylinderRadius = 100;
    float numCircumference = 20;
    float numVertical = 12;


    ofBackground(0);
    ofPushMatrix();
    ofTranslate(cylinderX, cylinderY);
    ofDrawLine(0, 0, 0, cylinderHeight);

    ofRotateYDeg(yRotationAngleDeg);

    for (int y = 0; y < numVertical; ++y)
    {
        for (int i = 0; i < numCircumference; ++i)
        {
            ofPushMatrix();
            ofRotateYDeg(i * 360.0f / numCircumference);

            ofPushMatrix();
            ofTranslate(0, y * cylinderHeight / numVertical, cylinderRadius);
            ofScale(.1);

            image.draw(-image.getWidth() / 2, -image.getHeight() / 2);

            ofPopMatrix();
            ofPopMatrix();
        }
    }

    ofPopMatrix();
}




void ofApp::mouseReleased(int x, int y, int button)
{
    yRotationAngularVelocity = 10;
}
