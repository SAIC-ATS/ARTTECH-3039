#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);

    rainbowPixels = makeRainbowPixels(400, 400);
    rainbowTexture.loadData(rainbowPixels);

    shuffledRainbowPixels = rainbowPixels;
    shuffledRainbowTexture.loadData(shuffledRainbowPixels);
    
    
    for (std::size_t y = 0; y < shuffledRainbowPixels.getHeight(); ++y)
    {
        rowOffsets.push_back(0);
        rowVelocities.push_back(0);
    }
}


void ofApp::update()
{
    for (std::size_t y = 0; y < rowOffsets.size(); ++y)
    {
        rowVelocities[y] *= 0.8; // Drag
        
        rowOffsets[y] += rowVelocities[y];
    }
    
    // Create my shuffled image ...
    for (std::size_t x = 0; x < shuffledRainbowPixels.getWidth(); ++x)
    {
        for (std::size_t y = 0; y < shuffledRainbowPixels.getHeight(); ++y)
        {
            std::size_t shuffledX = (x + std::size_t(rowOffsets[y])) % shuffledRainbowPixels.getWidth();
            std::size_t shuffledY = y;

            ofColor shuffledColor = rainbowPixels.getColor(shuffledX, shuffledY);

            shuffledRainbowPixels.setColor(x, y, shuffledColor);
        }
    }

    // Updated my texture .
    shuffledRainbowTexture.loadData(shuffledRainbowPixels);
}


void ofApp::draw()
{
    ofSetColor(255);
    shuffledRainbowTexture.draw(0, 0);
    rainbowTexture.draw(shuffledRainbowTexture.getWidth(), 0);
}


void ofApp::mouseDragged(int x, int y, int button)
{
}


void ofApp::mousePressed(int x, int y, int button)
{
    // Based on where the mouse is -- change the y
    
    
    for (std::size_t i = 0; i < rowOffsets.size(); ++i)
    {
        rowVelocities[i] = 1000; // Drag
    }
}


void ofApp::mouseReleased(int x, int y, int button)
{
}


ofPixels ofApp::makeRainbowPixels(std::size_t width, std::size_t height)
{
    ofPixels pixels;
    pixels.allocate(width, height, OF_PIXELS_RGB);
    
    for (std::size_t x = 0; x < pixels.getWidth(); ++x)
    {
        for (std::size_t y = 0; y < pixels.getHeight(); ++y)
        {
            ofColor color = ofColor::fromHsb(ofMap(x, 0, pixels.getWidth(), 0, 255),
                                             ofMap(y, 0, pixels.getHeight(), 0, 255),
                                             255);
            pixels.setColor(x, y, color);
        }
    }

    return pixels;
}

