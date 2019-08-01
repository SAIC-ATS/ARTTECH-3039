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
        texture.draw(position, radius * 2, radius * 2);
    }
    
    //// Data
    // Attributes / Member Variables
    glm::vec2 position;
    glm::vec2 velocity;
    ofColor color;
    float radius = 10;
    
    bool isDead = false;

    ofTexture texture;
    
};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void makeParticle();
    
    std::vector<Particle> particles;
    
    glm::vec2 gravity;

    ofTexture texture;
    
};
