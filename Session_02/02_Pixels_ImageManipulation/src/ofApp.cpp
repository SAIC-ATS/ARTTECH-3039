#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    ofLoadImage(myPixels, "puppy.jpg");
    myTexture.loadData(myPixels);
    
}


void ofApp::update()
{
    // Make a copy to play with!
    ofPixels tmpPixels = myPixels;
    
    for (std::size_t x = 0; x < tmpPixels.getWidth(); x++)
    {
        for (std::size_t y = 0; y < tmpPixels.getHeight(); y++)
        {
            ofColor color = tmpPixels.getColor(x, y);

            if (x > tmpPixels.getWidth() / 2)
            {
                // color.r = (255 - color.r);
                // color.g = (255 - color.g);
                // color.b = (255 - color.b);
                color = color.getInverted();
            }
    
            tmpPixels.setColor(x, y, color);
            
        }
    }
    
    myTexture.loadData(tmpPixels);
}


void ofApp::draw()
{
    myTexture.draw(0, 0);
}


void ofApp::keyPressed(int key)
{
}

