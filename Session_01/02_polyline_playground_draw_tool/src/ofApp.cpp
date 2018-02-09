#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    gui.setup();
    gui.add(drawTool.parameters());
    gui.add(resampleSpacing.set("Resample Spacing", 25, 5, 100));

    resampleSpacingListener = resampleSpacing.newListener([&](float spacing) {
        resampledPoly = poly.getResampledBySpacing(spacing);
    });

    ofAddListener(drawTool.onPolyline, this, &ofApp::onPolyline);
}


void ofApp::draw()
{
    ofNoFill();

    // Draw the polyline in gray.
    ofSetColor(120);
    drawTool.draw();
    
    ofSetColor(255);
    ofDrawBitmapString("Draw Here", 14, ofGetHeight() - 14);

    // Draw the resampled polyline on the right half of the screen.
    ofFill();
    ofSetColor(127);
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, 0);
    ofDrawRectangle(0, 0, ofGetWidth() / 2, ofGetHeight());
    
    
    // Draw the resampled polyline in yellow.
    ofSetColor(ofColor::yellow);
    resampledPoly.draw();
    // Draw its vertices.
    ofSetColor(255, 255, 127);
    for (auto vertex: resampledPoly.getVertices())
    {
        ofDrawCircle(vertex, 3);
    }
    
    ofSetColor(255);
    ofDrawBitmapString("Resampled by Spacing", 14, ofGetHeight() - 14);


    float time = ofGetElapsedTimef();

    for (std::size_t i = 0; i < resampledPoly.size(); i++)
    {
        float phase = ofMap(i, 0, resampledPoly.size(), 0, glm::pi<float>());
        float scaling = 25 * sin(time + phase);

        // The normal is a normalized vector representing the "Normal" direction.
        glm::vec3 theNormal = resampledPoly.getNormalAtIndex(i);
        // First we stretch it to the length we want.
        glm::vec3 theScaledNormal = theNormal * scaling;
        glm::vec3 vertex = resampledPoly[i];
        // Then we translate it to get its position relative to the vertex.
        glm::vec3 positiveNormalVertexOffset = vertex + theScaledNormal;
        glm::vec3 negativeNormalVertexOffset = vertex - theScaledNormal;

        ofSetColor(255, 80);
        ofDrawCircle(positiveNormalVertexOffset, scaling / 3);
        ofDrawLine(vertex, positiveNormalVertexOffset);
        ofSetColor(255, 0, 0, 80);
        ofDrawCircle(negativeNormalVertexOffset, scaling / 3);
        ofDrawLine(vertex, negativeNormalVertexOffset);
    }
    
    ofPopMatrix();
    
    gui.draw();

}


void ofApp::onPolyline(ofPolyline& polyline)
{
    poly = polyline;
    resampledPoly = poly.getResampledBySpacing(resampleSpacing);
}


