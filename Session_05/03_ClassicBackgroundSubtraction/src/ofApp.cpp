#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);

    grabber.setup(640, 480);
    
}


void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew() || ofGetFrameNum() == 0)
    {
        // Set the background pixels to something if it is empty.
        if (!backgroundPixels.isAllocated())
        {
            backgroundPixels = grabber.getPixels();
        }
        
        // Update pixels, background stuff, etc.
        foregroundPixels = grabber.getPixels();
        binaryPixels = grabber.getPixels();

        for (std::size_t x = 0; x < foregroundPixels.getWidth(); ++x)
        {
            for (std::size_t y = 0; y < foregroundPixels.getHeight(); ++y)
            {
                ofColor currentPixelColor = foregroundPixels.getColor(x, y);
                ofColor backgroundPixelColor = backgroundPixels.getColor(x, y);
                
                // Calculate the absolute difference between the background frame and the current frame.
                ofColor differencePixelColor;
                differencePixelColor.r = std::abs(currentPixelColor.r - backgroundPixelColor.r);
                differencePixelColor.g = std::abs(currentPixelColor.g - backgroundPixelColor.g);
                differencePixelColor.b = std::abs(currentPixelColor.b - backgroundPixelColor.b);
                
                // Get the brightness of the difference frame.
                float differenceBrightness = differencePixelColor.getBrightness();
                
                // Determine the color for the binary image's corresponding pixel.
                ofColor binaryDifferenceColor = ofColor(0);
                
                // Set the pixel color to white if it is bright enough and keep it at black if it is not.
                if (differenceBrightness > binaryThreshold)
                    binaryDifferenceColor = ofColor(255);

                // Finally set the values of our two pixel sets.
                foregroundPixels.setColor(x, y, differencePixelColor);
                binaryPixels.setColor(x, y, binaryDifferenceColor);
            }
        }
        
        // Upload all textures.
        backgroundTexture.loadData(backgroundPixels);
        foregroundTexture.loadData(foregroundPixels);
        binaryTexture.loadData(binaryPixels);
        maskedTexture = grabber.getTexture();
        maskedTexture.setAlphaMask(binaryTexture);
    }
}


void ofApp::draw()
{
    float w = ofGetWidth() / 2;
    float h = ofGetHeight() / 2;
    
    maskedTexture.draw(0, 0, w, h);
    backgroundTexture.draw(w, 0, w, h);
    foregroundTexture.draw(0, h, w, h);
    binaryTexture.draw(w, h, w, h);
}


void ofApp::keyPressed(int key)
{
    if (key == 'b')
    {
        // Capture background.
        backgroundPixels = grabber.getPixels();
    }
    else if (key == '-')
    {
        // Make threshold smaller.
        binaryThreshold--;
        binaryThreshold = ofClamp(binaryThreshold, 0, 255);
    }
    else if (key == '=')
    {
        // Make threshold bigger.
        binaryThreshold++;
        binaryThreshold = ofClamp(binaryThreshold, 0, 255);
    }
}

