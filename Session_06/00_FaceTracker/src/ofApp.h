// ofxFaceTrack2 example: SIMPLE EXAMPLE
//
// This example shows minimal usage of the ofxFaceTracker2 addon,
// doing simple landmark detection and pose estimation
//

#pragma once

#include "ofMain.h"
#include "ofxFaceTracker2.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    ofMesh getMeshForFeature(const ofPolyline& poly);

    ofxFaceTracker2 tracker;
    ofVideoGrabber grabber;


    ofPolyline leftEye;
    ofPolyline rightEye;

    ofMesh leftEyeMesh;
    ofMesh rightEyeMesh;

};
