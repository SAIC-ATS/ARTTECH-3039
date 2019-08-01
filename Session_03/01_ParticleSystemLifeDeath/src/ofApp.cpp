#include "ofApp.h"


void ofApp::setup()
{
    ofSetVerticalSync(true); // Synchronize to monitor framerate.
    
    ofBackground(80);
    
    // Set gravity.
    gravity = { 0, 1 };
    
    ofLoadImage(texture, "dot.png");
}


void ofApp::update()
{
    while (particles.size() < 500)
    {
        makeParticle();
    }

    float w = ofGetWidth();
    float h = ofGetHeight();
    ofRectangle screenRectangle(0, 0, w, h);
    screenRectangle.scaleFromCenter(1.5);
    
    
    glm::vec2 screenCenter = { w / 2, h / 2 };
    glm::vec2 mousePosition = { ofGetMouseX(), ofGetMouseY() };
    gravity = (mousePosition - screenCenter) * 0.01;

    for (std::size_t i = 0; i < particles.size(); i++)
    {
        // Add gravity to our velocity.
        particles[i].velocity += gravity;
        
        particles[i].update();

        if (screenRectangle.inside(particles[i].position))
        {
            // The particle is still inside the screen.
        }
        else
        {
            // It is off screen.
            particles[i].isDead = true;
        }
    }

    // Remove any particles that are marked as isDead == true.
    // std::vector<Particle>::iterator iter = particles.begin();
    auto iter = particles.begin();
    while (iter != particles.end())
    {
        if (iter->isDead)
        {
            iter = particles.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    

// Super C++!
//    particles.erase(std::remove_if(particles.begin(), particles.end(),
//                                   [](const Particle& particle)
//                                   {
//                                       return particle.isDead;
//                                   }),
//                    particles.end());
}


void ofApp::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (std::size_t i = 0; i < particles.size(); i++)
    {
        particles[i].draw();
    }
    ofDisableBlendMode();
    
    ofDrawBitmapStringHighlight(ofToString(particles.size()) + " particles", 40, 40);
}


void ofApp::makeParticle()
{
    Particle p;
    
    p.position.x = ofGetWidth() / 2.;
    p.position.y = ofGetHeight() / 2.;
    
    p.radius = ofRandom(50, 200);
    p.color = ofColor::fromHsb(ofRandom(80, 100), 255, 255, 20);
    
    p.velocity.x = ofRandom(-5, 5);
    p.velocity.y = ofRandom(-5, 5);
    
    p.texture = texture;
    
    particles.push_back(p);
}
