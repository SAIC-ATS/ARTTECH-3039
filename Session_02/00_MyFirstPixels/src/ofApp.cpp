#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::draw()
{
    ofPixels myPixels;
    myPixels.allocate(80, 80, OF_PIXELS_RGB);
    
    for (std::size_t x = 0; x < myPixels.getWidth(); x++)
    {
        for (std::size_t y = 0; y < myPixels.getHeight(); y++)
        {
            if (x > myPixels.getWidth() / 2)
            {
                ofColor myNewColor = ofColor::yellow;
                myPixels.setColor(x, y, myNewColor);
            }
            else
            {
                ofColor myNewColor = ofColor::fuchsia;
                myPixels.setColor(x, y, myNewColor);
            }
        }
    }
    
    ofTexture myTexture;
    myTexture.loadData(myPixels);
    myTexture.draw(0, 0);
}

