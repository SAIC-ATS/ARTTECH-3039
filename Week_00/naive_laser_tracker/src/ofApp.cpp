#include "ofApp.h"
#include "ofxPS3EyeGrabber.h"


void ofApp::setup()
{
    // Set the window size.
    ofSetWindowShape(640, 480);

    // Use the PS3 Eye camera.
    grabber.setGrabber(std::make_shared<ofxPS3EyeGrabber>());

    // Set up the camera.
    grabber.setup(640, 480);
}


void ofApp::update()
{
    // Update the camera.
    grabber.update();

    // If the frame is new ...
    if (grabber.isFrameNew())
    {
        // Set a super small brightness to compare against.
        float maxBrightness = std::numeric_limits<float>::lowest();

        // Get a copy of the pixels.
        ofPixels pixels = grabber.getPixels();

        // Iterate through each pixel.
        for (std::size_t x = 0; x < pixels.getWidth(); ++x)
        {
            for (std::size_t y = 0; y < pixels.getHeight(); ++y)
            {
                // Get the brightness for the current pixel.
                float brightness = pixels.getColor(x, y).getBrightness();

                // If the brightness is greater than the current maximum brightness ...
                if (brightness > maxBrightness)
                {
                    // Save the location x and y ...
                    maxX = x;
                    maxY = y;

                    // ... and save the brightness calculated.
                    maxBrightness = brightness;
                }
            }
        }

        // 
        polyline.addVertex(maxX, maxY);

        if (polyline.size() > 500)
        {
            polyline.clear();
        }
    }
}


void ofApp::draw()
{
    grabber.draw(0, 0);

    ofNoFill();
    ofDrawCircle(maxX, maxY, 20);

    polyline.draw();
}








