#pragma once


#include "ofMain.h"
#include "ofxARTTECH3039.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void onPolyline(ofPolyline& polyline);
    
    PolylineDrawTool drawTool;
    ofxPanel gui;

    ofParameter<float> resampleSpacing;
    ofEventListener resampleSpacingListener;

    ofPolyline poly;
    ofPolyline resampledPoly;

};
