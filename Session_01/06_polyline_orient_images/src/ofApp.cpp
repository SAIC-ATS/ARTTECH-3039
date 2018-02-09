#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    image.load("puppy.png");
}


void ofApp::draw()
{
    path.draw();

    ofSetColor(255);
    for (std::size_t i = 0; i < resampledPoly.size(); i++)
    {
        glm::vec3 theTangent = resampledPoly.getTangentAtIndex(i);

        // Determine the rotation of the tangent.
        float angleRad = std::atan2f(theTangent.y, theTangent.x);

        // Translate and rotate the image.
        ofPushMatrix();
        ofTranslate(resampledPoly[i]);
        ofRotateRad(angleRad);
        // Draw the image centered.
        image.draw(-image.getWidth() / 2, -image.getHeight() / 2 - 4);
        ofPopMatrix();
    }
}


void ofApp::mouseDragged(int x, int y, int button)
{
    addPoint(x, y);
}


void ofApp::mousePressed(int x, int y, int button)
{
    poly.clear();
    poly.close();
    addPoint(x, y);
}


void ofApp::mouseReleased(int x, int y, int button)
{
    addPoint(x, y);
}


void ofApp::addPoint(int x, int y)
{
    poly.addVertex(x, y);
    resampledPoly = poly.getResampledBySpacing(image.getWidth() * 0.8);
    path.clear();
    path.setFillColor(ofColor::pink);

    if (resampledPoly.size() > 0)
    {
        path.moveTo(resampledPoly[0]);
        
        for (auto vertex: resampledPoly)
            path.lineTo(vertex);
        
    }
}
