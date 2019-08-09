#include "ofApp.h"


void ofApp::setup()
{
    ofEnableDepthTest();
}


void ofApp::draw()
{
    cam.begin();

//    for (std::size_t i = 0; i < vertices.size(); i++)
//    {
//        ofSetColor(colors[i]);
//        ofDrawCircle(vertices[i], 10);
//    }

    mesh.draw();
    cam.end();
}


void ofApp::mousePressed(int x, int y, int button)
{
    // Add a vertex.
    vertices.push_back({x - ofGetWidth() / 2,
                        y - ofGetHeight() / 2,
                        ofRandom(-500, 500)});

    // Add a color.
    colors.push_back(ofFloatColor::fromHsb(ofRandom(1), 1, 1));

    // Construct the mesh.
    mesh.clear();
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.addVertices(vertices);
    mesh.addColors(colors);
}

