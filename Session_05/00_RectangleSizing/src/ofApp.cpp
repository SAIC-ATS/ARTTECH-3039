#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    grabber.setup(1280, 720);

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
    float scaleX = ofGetWidth() / grabber.getWidth();
    float scaleY = ofGetHeight() / grabber.getHeight();
    
    ofPushMatrix();
    ofScale(scaleX, scaleY);

    ofSetColor(255);
    grabber.draw(0, 0);

    ofSetColor(ofColor::yellow);
    ofNoFill();
    for (std::size_t i = 0; i < finder.size(); i++)
    {
        ofRectangle objectRectangle = finder.getObject(i);
        ofDrawRectangle(objectRectangle);
    }
    
    ofPopMatrix();
}


void ofApp::keyPressed(int key)
{
}


void ofApp::keyReleased(int key)
{
}


void ofApp::mouseMoved(int x, int y)
{
}


void ofApp::mouseDragged(int x, int y, int button)
{
}


void ofApp::mousePressed(int x, int y, int button)
{
}


void ofApp::mouseReleased(int x, int y, int button)
{
}


void ofApp::mouseEntered(int x, int y)
{
}


void ofApp::mouseExited(int x, int y){

}


void ofApp::windowResized(int w, int h)
{
}


void ofApp::gotMessage(ofMessage msg)
{
}


void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
