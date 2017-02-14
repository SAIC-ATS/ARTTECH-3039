#include "ofApp.h"


void ofApp::setup()
{
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofBackground(0);
    
    ofSetColor(255, 255, 0, 150);

    for (auto c: circles)
    {
        ofDrawCircle(c.center(), c.radius());
    }

    ofSetColor(255, 255,0);
    ofNoFill();
    ofBeginShape();
    for(auto point: polyline)
    {
        ofCurveVertex(point);
    }
    ofEndShape();

    ofSetColor(255);
    for (auto i = 0; i < polyline.size(); ++i)
    {
        if (i > 0)
            ofDrawLine(polyline[i-1], polyline[i]);

        float scale = 10.0;

        auto normal = polyline.getNormalAtIndex(i);

        auto normalEnd0 = normal *  scale + polyline[i];
        auto normalEnd1 = normal * -scale + polyline[i];

        ofDrawLine(normalEnd0, normalEnd1);
    }

    ofSetColor(0,255,0);

    int radius = 4;

    for (auto point: polyline)
    {
        ofDrawCircle(point, radius);
    }
}


void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        circles.clear();
        polyline.clear();
    }
}


void ofApp::mouseDragged(int x, int y, int button)
{
    addPoint(x, y);
}


void ofApp::mousePressed(int x, int y, int button)
{
    addPoint(x, y);
}


void ofApp::addPoint(float x, float y)
{
    polyline.addVertex(x, y);

    int i = polyline.size();

    Circle c;

    if (i > 2 && Circle::fromPoints(polyline[i-1], polyline[i-2], polyline[i-3], c))
    {
        circles.push_back(c);
    }
}
