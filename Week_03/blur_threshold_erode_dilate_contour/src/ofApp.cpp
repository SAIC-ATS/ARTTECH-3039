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
    gui.add(blurLevel.set("Blur Level", 0, 0, 30));
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(erodeIterations.set("Erode Iterations", 0, 0, 30));
    gui.add(dilateIterations.set("Dilate Iterations", 0, 0, 30));
    gui.add(invert.set("Invert", false));

    gui.add(contourMinArea.set("Contour Min Area", 10, 1, 100));
    gui.add(contourMaxArea.set("Contour Max Area", 200, 1, 500));
    gui.add(contourThreshold.set("Contour Threshold", 128, 0, 255));
    gui.add(contourHoles.set("Contour Holes", false));
    gui.add(contourSimplify.set("Contour Simplify", true));

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


        contourFinder.setMinAreaRadius(contourMinArea);
        contourFinder.setMaxAreaRadius(contourMaxArea);
        contourFinder.setThreshold(contourThreshold);
        contourFinder.setFindHoles(contourHoles);
        contourFinder.setSimplify(contourSimplify);
        contourFinder.findContours(binaryPixels);

        binaryTexture.loadData(binaryPixels);
    }
}


void ofApp::draw()
{
    ofFill();
    ofSetColor(255);
    video.draw(0, 0);

    ofPushStyle();
    ofSetLineWidth(3);

    for (auto i = 0; i < contourFinder.size(); ++i)
    {
        if (contourFinder.getHole(i))
        {
            ofSetColor(ofColor::red);
        }
        else
        {
            ofSetColor(ofColor::green);
        }

        contourFinder.getPolyline(i).draw();

        auto label = contourFinder.getLabel(i);

        auto age = contourFinder.getTracker().getAge(label);

        ofDrawBitmapStringHighlight(ofToString(label) + " : " + ofToString(age), ofxCv::toOf(contourFinder.getCenter(i)));

    }
    ofPopStyle();

    binaryTexture.draw(640, 0);

    gui.draw();
}
