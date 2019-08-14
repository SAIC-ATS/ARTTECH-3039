#pragma once


#include "ofMain.h"
#include "ofxDlib.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void dragEvent(ofDragInfo dragInfo) override;

    ofxDlib::FaceDetector detector;
    ofxDlib::FaceShapePredictor shapePredictor;
    ofxDlib::FaceCoder coder;

    // A map of all of our pixels for each folder.
    std::map<std::string, std::vector<ofPixels>> pixelMap;

    // The aligned versions of the faces found in the pixelMap above.
    std::map<std::string, std::vector<ofTexture>> faceChipsMap;

    // The face codes for each of the face chips.
    std::map<std::string, std::vector<std::vector<float>>> faceCodeMap;

    std::string matchingClass;

};
