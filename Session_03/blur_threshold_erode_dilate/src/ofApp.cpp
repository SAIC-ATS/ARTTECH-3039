#include "ofApp.h"


void ofApp::setup()
{
    video.load("hands.mp4");
    video.play();

    binaryPixels.allocate(video.getWidth(),
                          video.getHeight(),
                          OF_PIXELS_GRAY);

    binaryTexture.loadData(binaryPixels);

    gui.setup();
    gui.add(blurLevel.set("Blur", 0, 0, 30));
    gui.add(erodeIterations.set("Erode Iterations", 0, 0, 30));
    gui.add(dilateIterations.set("Dilate Iterations", 0, 0, 30));
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(invert.set("Invert", false));
}


void ofApp::update()
{
    video.update();

    if (video.isFrameNew())
    {
        ofxCv::convertColor(video, binaryPixels, CV_RGB2GRAY);
        ofxCv::blur(binaryPixels, binaryPixels, blurLevel);
        ofxCv::threshold(binaryPixels, binaryPixels, threshold, invert);
        ofxCv::erode(binaryPixels, binaryPixels, erodeIterations);
        ofxCv::dilate(binaryPixels, binaryPixels, dilateIterations);

        binaryTexture.loadData(binaryPixels);
    }
}


void ofApp::draw()
{
    video.draw(0, 0);
    binaryTexture.draw(640, 0);

    gui.draw();
}
