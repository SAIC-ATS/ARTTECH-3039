#include "ofApp.h"


void ofApp::setup()
{
    // Specify the dimensions of our image.
    std::size_t imageWidth = 50;
    std::size_t imageHeight = 50;

    // Create an FBO (frame buffer object) that we can draw on.
    ofFbo fbo;
    // We need to tell the FBO what its size should be.
    fbo.allocate(imageWidth, imageHeight);

    // We instantiate a json structure.
    // We can learn more about that from this website.
    // https://github.com/nlohmann/json/
    ofJson json;

    // We are going to create this many squares.
    std::size_t numSquares = 1000;

    for (std::size_t i = 0; i < numSquares; ++i)
    {
        // Generate random squares.
        int width = ofRandom(5, imageWidth);
        int height = ofRandom(5, imageHeight);

        // We want to make sure that the squares stay fully on the FBO.
        int x = ofRandom(0, imageWidth - width);
        int y = ofRandom(0, imageHeight - height);

        // Generate random RGB colors.
        int red = ofRandom(255);
        int green = ofRandom(255);
        int blue = ofRandom(255);

        // Begin rendering on the FBO.
        // Everything between fbo.begin() and fbo.end(), will be
        // rendered on the FBO.
        fbo.begin();
        // Draw the background black rectangle.
        ofSetColor(ofColor::black);
        ofFill();
        ofDrawRectangle(0, 0, imageWidth, imageHeight);

        // Draw our random rectangle.
        ofSetColor(red, green, blue);
        ofDrawRectangle(x, y, width, height);

        // End rendering on the FBO.
        fbo.end();

        // Create some pixels in RAM so that we can save them to disk.
        ofPixels pixels;
        // The FBO is on the GPU and so we have to read it back to RAM.
        fbo.readToPixels(pixels);

        // Now we want to save the images to PNG files.
        std::string filename = ofToString(i, 4, '0') + ".png";
        ofSaveImage(pixels, filename);

        // We also want to save an entry for this data.
        ofJson entry;

        entry["width"] = width;
        entry["height"] = height;
        entry["x"] = x;
        entry["y"] = y;
        entry["red"] = red;
        entry["green"] = green;
        entry["blue"] = blue;
        entry["filename"] = filename;

        // Add the data to our json structure.
        json.push_back(entry);
    }

    // Save our JSON file for use elsewhere.
    ofSavePrettyJson("squares.json", json);

    // Exit so the program won't just keep running forever.
    ofExit();
}

