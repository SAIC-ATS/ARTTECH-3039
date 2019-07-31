#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    ofSetWindowShape(400, 400);
}


void ofApp::draw()
{
    ofPixels myPixels;
    myPixels.allocate(ofGetWidth(), ofGetHeight(), OF_PIXELS_RGB);

    std::vector<ofColor> colors = {
        ofColor::red,
        ofColor::orange,
        ofColor::yellow,
        ofColor::green,
        ofColor::blue,
        ofColor::indigo,
        ofColor::violet
    };

    for (std::size_t x = 0; x < myPixels.getWidth(); ++x)
    {
        for (std::size_t y = 0; y < myPixels.getHeight(); ++y)
        {
            std::size_t index = ofMap(x, 0, myPixels.getWidth(), 0, colors.size(), true);
            myPixels.setColor(x, y, colors[index]);
        }
    }

    ofTexture myTexture;
    myTexture.loadData(myPixels);
    myTexture.draw(0, 0);

}
