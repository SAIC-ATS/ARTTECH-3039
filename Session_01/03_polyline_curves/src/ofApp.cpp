#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
}


void ofApp::draw()
{
    ofNoFill();

    ofSetColor(120);
    poly.draw();

    // Draw the resampled polyline in yellow.
    ofSetColor(ofColor::yellow);
    resampledPoly.draw();
    for (auto vertex: resampledPoly.getVertices())
    {
        ofDrawCircle(vertex, 3);
    }

    for (std::size_t i = 0; i < resampledPoly.size(); i++)
    {
        // The curvatures are normalized where 0 is a straight line and 1 is a 360 turn.
        float scaling = 1000 * curvatures[i];

        // The normal is a normalized vector representing the "Normal" direction.
        glm::vec3 theNormal = resampledPoly.getNormalAtIndex(i);
        glm::vec3 theScaledNormal = theNormal * scaling;
        glm::vec3 vertex = resampledPoly[i];
        glm::vec3 ourOffsetInTheNormalDirection = vertex + theScaledNormal;

        ofSetColor(255);
        ofDrawCircle(ourOffsetInTheNormalDirection, 4);
        ofDrawLine(vertex, ourOffsetInTheNormalDirection);
    }
}


void ofApp::mouseDragged(int x, int y, int button)
{
    poly.curveTo(x, y);
}


void ofApp::mousePressed(int x, int y, int button)
{
    poly.clear();
    poly.curveTo(x, y);
}


void ofApp::mouseReleased(int x, int y, int button)
{
    poly.curveTo(x, y);

    // Make a copy of the current polyline.
    // resampledPoly = poly.getResampledByCount(10);
    resampledPoly = poly.getResampledBySpacing(20);

    // The curvature finding algorithm is in the addon.
    curvatures = CvUtils::getCurvatures(resampledPoly);
    // curvatures = CvUtils::smooth(curvatures, 0.75);
}
