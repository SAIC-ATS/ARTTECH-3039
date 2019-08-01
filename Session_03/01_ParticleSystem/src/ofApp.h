#pragma once


#include "ofMain.h"


class Particle
{
public:
    //// Behaviors
    void update()
    {
        position += velocity;
    }

    // Member functions / Member methods
    void draw()
    {
        ofSetColor(color);
        ofDrawCircle(position, radius);
    }
    
    //// Data
    // Attributes / Member Variables
    glm::vec2 position;
    glm::vec2 velocity;
    ofColor color;
    float radius = 10;

};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    std::vector<Particle> particles;

};
