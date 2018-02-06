#include "ofApp.h"


void ofApp::setup()
{
    // Set the window size.
    ofSetWindowShape(640, 480);

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
                ofColor color = pixels.getColor(x, y);

                float brightness = color.getBrightness();

                // if we want to use the red value as opposed to the brightness,
                // then we might do this:
                //    brightness = color.r;

                // If the brightness is greater than the current maximum brightness ...
                if (brightness > maxBrightness)
                {
                    // Save the location x and y ...
                    xPosition = x;
                    yPosition = y;

                    // ... and save the brightness calculated.
                    maxBrightness = brightness;
                }
            }
        }

        // Add each point to a polyline.
        polyline.addVertex(xPosition, yPosition);

        // When the polyline gets pretty big, clear it.
        if (polyline.size() > 500)
        {
            polyline.clear();
        }
    }
}


void ofApp::draw()
{
    // Draw the camera.
    grabber.draw(0, 0);

    // Draw a circle with the current location.
    ofNoFill();
    ofDrawCircle(xPosition, yPosition, 20);

    // Draw the current polyline.
    polyline.draw();
}








