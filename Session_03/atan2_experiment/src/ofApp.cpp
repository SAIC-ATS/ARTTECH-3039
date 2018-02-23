#include "ofApp.h"


void ofApp::draw()
{
    ofBackground(0);

    glm::vec2 mousePosition(ofGetMouseX(), ofGetMouseY());
    glm::vec2 screenCenter(ofGetWidth() / 2, ofGetHeight() / 2);

    glm::vec2 diff = mousePosition - screenCenter;

    float angle = std::atan2(diff.y, diff.x);

    float distance = glm::distance(mousePosition, screenCenter);

    float h = 10;
    glm::vec2 t0(0, h);
    glm::vec2 t1(0, -h);
    glm::vec2 t2(distance, 0);

    ofPushMatrix();
    ofTranslate(screenCenter);
    ofRotateRad(angle);
    ofDrawTriangle(t0, t1, t2);
    ofPopMatrix();
}
