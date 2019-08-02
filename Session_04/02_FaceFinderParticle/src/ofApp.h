#pragma once


#include "ofMain.h"
#include "ofxCv.h"


class Particle
{
public:
    void draw()
    {
        float alivenessFactor = ofClamp(age / 60.f, 0, 1);

        ofColor deathColor(255, 0);
        ofColor drawColor = color.getLerped(deathColor, alivenessFactor);
        ofSetColor(drawColor);
        
        float drawWidth = ofMap(alivenessFactor, 0, 1, texture.getWidth(), 10 * texture.getWidth());
        float drawHeight = ofMap(alivenessFactor, 0, 1, texture.getHeight(), 10 * texture.getHeight());

        texture.draw(position, drawWidth, drawHeight);
    }
    
    void update()
    {
        position += velocity;
        age++;
    }
    
    glm::vec2 position;
    glm::vec2 velocity;
    ofTexture texture;
    ofColor color;
    std::size_t age = 0;
};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    ofVideoGrabber grabber;
    ofxCv::ObjectFinder finder;
  
    std::vector<Particle> particles;
    ofTexture rightEyeTexture;
    ofTexture leftEyeTexture;

    ofPixels eyeMask;
};
