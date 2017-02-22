#pragma once


#include "ofMain.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxBox2d.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    ofVideoPlayer video;

    ofPixels binaryPixels;
    ofTexture binaryTexture;

    ofxCv::ContourFinder contourFinder;

    ofxPanel gui;
    ofParameter<float> blurLevel;
    ofParameter<int> threshold;
    ofParameter<bool> invert;
    ofParameter<int> erodeIterations;
    ofParameter<int> dilateIterations;

    ofParameter<float> contourMinArea;
    ofParameter<float> contourMaxArea;
    ofParameter<float> contourThreshold;
    ofParameter<bool> contourHoles;
    ofParameter<bool> contourSimplify;


    // active holes.
    std::map<unsigned int, ofPolyline> holes;

    // Box2D
    ofxBox2d box2d;

    // The shapes I've created.
    std::vector<std::shared_ptr<ofxBox2dPolygon>> polyShapes;

};



