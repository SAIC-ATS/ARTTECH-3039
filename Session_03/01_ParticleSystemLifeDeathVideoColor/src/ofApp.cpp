#include "ofApp.h"


void ofApp::setup()
{
    ofSetVerticalSync(true); // Synchronize to monitor framerate.
    
    ofBackground(80);
    
    // Set gravity.
    gravity = { 0, 1 };
    
    ofLoadImage(myTextureToShareWithAllTheParticles, "dot.png");
    myTextureToShareWithAllTheParticles.setAnchorPercent(0.5, 0.5);
    
    grabber.setup(1024, 768);
}


void ofApp::update()
{
    grabber.update();
    
    
    while (particles.size() < 5000)
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
    ofSetColor(255);

    //grabber.draw(0, 0);
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (std::size_t i = 0; i < particles.size(); i++)
    {
//        std::size_t x = ofClamp(particles[i].position.x, 0, grabber.getWidth());
//        std::size_t y = ofClamp(particles[i].position.y, 0, grabber.getHeight());

//        particles[i].color = grabber.getPixels().getColor(x, y);
//        particles[i].color.a *= 0.5;
        particles[i].draw();
    }
    ofDisableBlendMode();
    
    ofDrawBitmapStringHighlight(ofToString(particles.size()) + " particles", 40, 40);
}


void ofApp::makeParticle()
{
    Particle p;
    
    p.position.x = ofRandomWidth();
    p.position.y = ofRandomHeight();
    
    p.radius = ofRandom(20, 50);
    
    std::size_t x = ofClamp(p.position.x, 0, grabber.getWidth());
    std::size_t y = ofClamp(p.position.y, 0, grabber.getHeight());

    p.color = grabber.getPixels().getColor(x, y);
    p.color.a *= 0.25;

    p.velocity.x = ofRandom(-5, 5);
    p.velocity.y = ofRandom(-5, 5);

    p.velocity *= 0.01;
    
    p.texture = myTextureToShareWithAllTheParticles;
    
    particles.push_back(p);
}
