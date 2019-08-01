#include "ofApp.h"


void ofApp::setup()
{
    ofSetVerticalSync(true); // Synchronize to monitor framerate.
    
    ofBackground(80);
    
    for (int i = 0; i < 1000; i++)
    {
        Particle p;

        p.position.x = ofRandomWidth();
        p.position.y = ofRandomHeight();

        p.radius = ofRandom(5, 10);
        p.color = ofColor::fromHsb(ofRandom(255), 255, 255, 200);

        p.velocity.x = ofRandom(-10, 10);
        p.velocity.y = ofRandom(-10, 10);
        
        particles.push_back(p);
    }
}


void ofApp::update()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    for (std::size_t i = 0; i < particles.size(); i++)
    {
        particles[i].update();
        
        // Right wall.
        if (particles[i].position.x + particles[i].radius > w)
        {
            particles[i].position.x = w - particles[i].radius;
            particles[i].velocity.x *= -1.0f;
        }

        // Left wall.
        if (particles[i].position.x - particles[i].radius < 0)
        {
            particles[i].position.x = particles[i].radius;
            particles[i].velocity.x *= -1.0f;
        }

        // Bottom wall.
        if (particles[i].position.y + particles[i].radius > h)
        {
            particles[i].position.y = h - particles[i].radius;
            particles[i].velocity.y *= -1.0f;
        }
        
        // Top wall.
        if (particles[i].position.y - particles[i].radius < 0)
        {
            particles[i].position.y = particles[i].radius;
            particles[i].velocity.y *= -1.0f;
        }
    }
}


void ofApp::draw()
{
    for (std::size_t i = 0; i < particles.size(); i++)
    {
        particles[i].draw();
    }
}

