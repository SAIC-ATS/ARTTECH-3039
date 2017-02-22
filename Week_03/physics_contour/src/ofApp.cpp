#include "ofApp.h"


void ofApp::setup()
{
    // The `hands.mp4` video used in these examples can be downloaded
    // [here](http://christopherbaker.net/dropbox/hands.mp4).
    video.load("hands.mp4");
    video.play();

    binaryPixels.allocate(video.getWidth(),
                          video.getHeight(),
                          OF_PIXELS_GRAY);

    binaryTexture.loadData(binaryPixels);

    gui.setup();
    gui.add(blurLevel.set("Blur Level", 17, 0, 30));
    gui.add(threshold.set("Threshold", 200, 0, 255));
    gui.add(erodeIterations.set("Erode Iterations", 0, 0, 30));
    gui.add(dilateIterations.set("Dilate Iterations", 0, 0, 30));
    gui.add(invert.set("Invert", true));

    gui.add(contourMinArea.set("Contour Min Area", 10, 1, 100));
    gui.add(contourMaxArea.set("Contour Max Area", 200, 1, 500));
    gui.add(contourThreshold.set("Contour Threshold", 128, 0, 255));
    gui.add(contourHoles.set("Contour Holes", true));
    gui.add(contourSimplify.set("Contour Simplify", true));

    // Box2d
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createGround();
    box2d.setFPS(30.0);

}


void ofApp::update()
{
    box2d.update();
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

    auto deadLabels = contourFinder.getTracker().getDeadLabels();

    for (auto deadLabel: deadLabels)
    {
        auto iter = holes.find(deadLabel);

        if (iter != holes.end())
        {
            ofPolyline polyline = iter->second;
            // Create the shape!

            auto poly = std::make_shared<ofxBox2dPolygon>();
            poly->addVertexes(polyline);
            poly->setPhysics(1.0, 0.3, 0.3);
            poly->triangulatePoly();
            poly->create(box2d.getWorld());
            polyShapes.push_back(poly);
        }
    }

    holes.clear();

    for (auto i = 0; i < contourFinder.size(); ++i)
    {
        auto label = contourFinder.getLabel(i);
        auto age = contourFinder.getTracker().getAge(label);

        if (contourFinder.getHole(i))
        {
            ofSetColor(ofColor::red);
            holes[label] = contourFinder.getPolyline(i);
        }
        else
        {
            ofSetColor(ofColor::green);
        }

        contourFinder.getPolyline(i).draw();

        ofDrawBitmapStringHighlight(ofToString(label) + " : " + ofToString(age), ofxCv::toOf(contourFinder.getCenter(i)));

    }
    ofPopStyle();

    binaryTexture.draw(640, 0);

    gui.draw();

    ofFill();
    ofSetColor(ofColor::blue);
    for (auto polygon: polyShapes)
    {
        polygon->draw();
    }
}
