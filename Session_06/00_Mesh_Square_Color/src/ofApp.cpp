#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::draw()
{
    glm::vec3 v0 = { 100, 100, 0 };
    glm::vec3 v1 = { 200, 100, 0 };
    glm::vec3 v2 = { 200, 200, 0 };
    glm::vec3 v3 = { 100, 200, 0 };

    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    std::vector<glm::vec3> vertices =
    {
        v0, v1, v2, v3
    };
    
    // A note about float colors and how they correspond to 8-bit ofColors.
    // ofColor greenColor = ofColor(0, 255, 127);
    // ofFloatColor greenColor = ofFloatColor(0, 1, 0.5);

    
    std::vector<ofFloatColor> colors = {
        ofFloatColor::red,
        ofFloatColor::green,
        ofFloatColor::blue,
        ofFloatColor::white
    };
    
    mesh.addVertices(vertices);
    mesh.addColors(colors);
    
    std::vector<ofIndexType> indices =
    {
        0, 1, 2,
        0, 2, 3
    };

    mesh.addIndices(indices);
    
    mesh.draw();
    
    
}

