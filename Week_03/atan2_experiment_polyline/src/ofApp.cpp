#include "ofApp.h"


void ofApp::draw()
{
    ofBackground(0);

    glm::vec2 mousePosition(ofGetMouseX(), ofGetMouseY());

    line.draw();

    float distance = 30;
    float h = 10;
    glm::vec2 t0(0, h);
    glm::vec2 t1(0, -h);
    glm::vec2 t2(distance, 0);

    for (auto point: line)
    {
        glm::vec2 diff = mousePosition - point;
        float angle = std::atan2(diff.y, diff.x);

        ofPushMatrix();
        ofTranslate(point);
        ofRotateRad(angle);
        ofDrawTriangle(t0, t1, t2);
        ofPopMatrix();
    }
}


void ofApp::mouseDragged(int x, int y, int button)
{
    line.addVertex(x, y);
}
