#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    ofLoadImage(myPixels, "puppy.jpg");
    myTexture.loadData(myPixels);
    
}


void ofApp::update()
{
    float brightestBrightness = 0;
    
    for (std::size_t x = 0; x < myPixels.getWidth(); x++)
    {
        for (std::size_t y = 0; y < myPixels.getHeight(); y++)
        {
            ofColor color = myPixels.getColor(x, y);
            
            float brightnessOfThisPixel = color.getBrightness();
            
            if (brightnessOfThisPixel >= brightestBrightness)
            {
                brightestBrightness = brightnessOfThisPixel;
                brightestX = x;
                brightestY = y;
            }
        }
    }
    
}


void ofApp::draw()
{
    ofSetColor(255);
    myTexture.draw(0, 0);
    
    ofNoFill();
    ofSetColor(ofColor::red);
    ofDrawCircle(brightestX, brightestY, 10);
}


void ofApp::keyPressed(int key)
{
}

