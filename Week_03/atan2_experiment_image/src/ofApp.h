#pragma once


#include "ofMain.h"
#include "Particle.h"
#include "ParticleSystem.h"


class PewPewParticle: public Particle
{
public:
    virtual ~PewPewParticle()
    {
    }

    virtual void draw() const
    {
        float angle = std::atan2(velocity.y, velocity.x);
        ofPushMatrix();
        ofTranslate(position);
        ofRotateRad(angle);
        ofScale(.2);
        ofPushStyle();
        ofFill();
        ofSetColor(255);
        texture.draw(0, 0);
        ofPopStyle();
        ofPopMatrix();
    }

    ofTexture texture;

};


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    ParticleSystem particles;

    std::vector<glm::vec2> emitters;

    ofTexture texture;
};
