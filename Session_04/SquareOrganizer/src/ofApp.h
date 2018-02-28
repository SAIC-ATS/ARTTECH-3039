#pragma once


#include "ofMain.h"
#include "ofxTSNE.h"


struct Square
{
    // The image of the square.
    ofTexture tex;

    // A list of features describing the image.
    std::vector<float> features;

    std::vector<float> featureProjection;

};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    std::vector<Square> squares;

    ofxTSNE tsne;

    std::vector<std::vector<double>> tsnePoints;

    bool runManually = true;
};
