#include "ofApp.h"


void ofApp::setup()
{
    ofLoadImage(texture, "pointer.png");

    for (auto i = 0; i < 1; ++i)
    {
        emitters.push_back(glm::vec2(ofRandomWidth(), ofRandomHeight()));
    }
}


void ofApp::update()
{
    particles.update();

    glm::vec2 mousePosition(ofGetMouseX(), ofGetMouseY());

    for (auto emitter: emitters)
    {
        if (ofRandom(1) > 0.75 && ofGetMousePressed())
        {
            auto particle = std::make_shared<PewPewParticle>();
            particle->position = emitter;
            particle->velocity = glm::normalize(mousePosition - emitter) * 10;
            particle->texture = texture;
            particles.particles.push_back(particle);
        }
    }
}


void ofApp::draw()
{
    ofBackground(0);
    particles.draw();
}
