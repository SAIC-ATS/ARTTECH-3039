#include "ofApp.h"


void ofApp::setup()
{
    myClass.startThread();
}


void ofApp::update()
{
    float i = 0;
    if (myClass.channel.tryReceive(i))
    {
        std::cout << "Got a  magic number! " << i << std::endl;
    }
}


void ofApp::draw()
{
    ofBackground(brightness);

    brightness++;

    if (brightness > 255) brightness = 0;
}


void ofApp::exit()
{
    myClass.stopThread();
    myClass.waitForThread();
}