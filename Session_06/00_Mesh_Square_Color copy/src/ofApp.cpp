#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::draw()
{
    glm::vec3 v0 = { -50, -50, -50 };
    glm::vec3 v1 = {  50, -50, -50 };
    glm::vec3 v2 = {  50,  50, -50 };
    glm::vec3 v3 = { -50,  50, -50 };

    glm::vec3 v4 = { -50, -50, 50 };
    glm::vec3 v5 = {  50, -50, 50 };
    glm::vec3 v6 = {  50,  50, 50 };
    glm::vec3 v7 = { -50,  50, 50 };

    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    std::vector<glm::vec3> vertices =
    {
        v0, v1, v2, v3, v4, v5, v6, v7
    };
    
    // A note about float colors and how they correspond to 8-bit ofColors.
    // ofColor greenColor = ofColor(0, 255, 127);
    // ofFloatColor greenColor = ofFloatColor(0, 1, 0.5);

    
    std::vector<ofFloatColor> colors = {
        ofFloatColor::red,
        ofFloatColor::green,
        ofFloatColor::blue,
        ofFloatColor::white,
        
        ofFloatColor::red.getInverted(),
        ofFloatColor::green.getInverted(),
        ofFloatColor::blue.getInverted(),
        ofFloatColor::white.getInverted()
    };
    
    mesh.addVertices(vertices);
    mesh.addColors(colors);
    
    std::vector<ofIndexType> indices =
    {
//        // Face 0
//        0, 1, 2,
//        0, 2, 3,
//
//        // Face 1
//        0, 4, 1,
//        1, 4, 5,
//
//        3, 2, 7,
//        2, 6, 7,
//
//        1, 5, 6,
//        1, 2, 6,
//
//        0, 3, 7,
//        0, 4, 7,
//
//        4, 5, 6,
//        4, 7, 6

        0, 2, 3,
        2, 7, 3,
        0, 7, 3

    };

    mesh.addIndices(indices);
    
    
    ofEnableDepthTest();
    camera.begin();
    mesh.draw();
    camera.end();
    ofDisableDepthTest();
    
    
}

