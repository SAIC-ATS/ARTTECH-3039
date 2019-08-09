#pragma once


#include "ofMain.h"
#include "ofxDlib.h"


class Person
{
public:
    // void draw() ...
    // void update() ...
    
    // Color is assigned when the track begins.
    ofColor color;

    // Face shape is updated each time the face is updated.
    std::vector<ofxDlib::FaceShape> faceShapes;
    std::vector<ofTexture> textures;
    std::vector<ofMesh> meshes;

};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    // This function will be called when the tracker finds a new id.
    void onTrackBegin(ofxDlib::FaceTrackerEventArgs& evt);

    // This function will be called when an existing id is updated with new info.
    void onTrackUpdate(ofxDlib::FaceTrackerEventArgs& evt);

    // This function will be called when an existing id is lost forever.
    void onTrackEnd(ofxDlib::FaceTrackerEventArgs& evt);

    ofVideoGrabber video;
    ofxDlib::FaceTracker tracker;

    // Database / aka Dictionary / aka Map
    // "Key" -> size_t, this is our label.
    // "Value" -> Person, this is the data associated with the person
    // who has the associated label.
    std::map<std::size_t, Person> database;

    // Each frame gets a number for future re-use.
    std::map<std::size_t, ofTexture> frameHistory;

};
