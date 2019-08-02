#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    grabber.setup(960, 720);
    
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ofxCv::ObjectFinder::Fast);
}


void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        finder.update(grabber.getPixels());
    }
}


void ofApp::draw()
{
    ofSetColor(ofColor::white);
    grabber.draw(0, 0);
    
    for (std::size_t i = 0; i < finder.size(); i++)
    {
        ofRectangle smoothedRect = finder.getObjectSmoothed(i);
        ofRectangle rect = finder.getObject(i);
        std::size_t label = finder.getLabel(i);
        std::size_t age = finder.getTracker().getAge(label);
        
        float eyeY = smoothedRect.getTop() + smoothedRect.getHeight() * 0.40;
        
        float faceWidth = smoothedRect.getWidth();
        float faceCenterX = smoothedRect.getCenter().x;
        
        float eyeRightX = faceCenterX + faceWidth * .2;
        float eyeLeftX = faceCenterX - faceWidth * .2;
        
        glm::vec2 eyeRight = { eyeRightX, eyeY };
        glm::vec2 eyeLeft = { eyeLeftX, eyeY };

        ofDrawCircle(eyeRight, 10);
        ofDrawCircle(eyeLeft, 10);

        
        // ofDrawLine(smoothedRect.getLeft(), eyeY, smoothedRect.getRight(), eyeY);
        // ofDrawLine(eyeRightX, smoothedRect.getTop(), eyeRightX, smoothedRect.getBottom());
        // ofDrawLine(eyeLeftX, smoothedRect.getTop(), eyeLeftX, smoothedRect.getBottom());
        
        // glm::vec2 center = smoothedRect.getCenter();
        // std::string info = ofToString(label) + " age: " + ofToString(age);
        // ofDrawBitmapString(info, center);
    }
}

