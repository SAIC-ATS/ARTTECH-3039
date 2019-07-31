#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    grabber.setup(1280, 720);
}


void ofApp::update()
{
    // Update the internal state of the video grabber.
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        // Get pixels.
        myPixels = grabber.getPixels();
        
        float brightestBrightness = 0;
        
        for (std::size_t x = 0; x < myPixels.getWidth(); x++)
        {
            for (std::size_t y = 0; y < myPixels.getHeight(); y++)
            {
                ofColor color = myPixels.getColor(x, y);
                
                float brightnessOfThisPixel = color.getBrightness();
                
                if (brightnessOfThisPixel > 127 && brightnessOfThisPixel >= brightestBrightness)
                {
                    brightestBrightness = brightnessOfThisPixel;
                    brightestX = x;
                    brightestY = y;
                }
            }
        }
    }
}


void ofApp::draw()
{
    ofSetColor(255);
    grabber.draw(0, 0);
    
    ofNoFill();
    ofSetColor(ofColor::red);
    ofDrawCircle(brightestX, brightestY, 10);
}


void ofApp::keyPressed(int key)
{
}

