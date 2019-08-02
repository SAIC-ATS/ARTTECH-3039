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
    grabber.draw(0, 0);
    
    // Debug draw.
    finder.draw();
}

