#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    ofSetWindowShape(400, 400);
}


void ofApp::draw()
{
    width = ofGetWidth();
    height = ofGetHeight();
    
    ofPixels myPixels;
    myPixels.allocate(width, height, OF_PIXELS_RGB);

    for (std::size_t x = 0; x < myPixels.getWidth(); ++x)
    {
        for (std::size_t y = 0; y < myPixels.getHeight(); ++y)
        {
            if (x < myPixels.getWidth() / 2)
            {
                if (y < myPixels.getHeight() / 2)
                {
                    myPixels.setColor(x, y, ofColor::yellow);
                }
                else
                {
                    myPixels.setColor(x, y, ofColor::blue);
                }
            }
            else
            {
                if (y < myPixels.getHeight() / 2)
                {
                    myPixels.setColor(x, y, ofColor::green);
                }
                else
                {
                    myPixels.setColor(x, y, ofColor::red);
                }
            }
        }
    }

    ofTexture myTexture;
    myTexture.loadData(myPixels);
    myTexture.draw(0, 0);

}
