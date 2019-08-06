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

//    ofDrawCircle(v0, 5);
//    ofDrawCircle(v1, 5);
//    ofDrawCircle(v2, 5);
//    ofDrawCircle(v3, 5);

    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_LINES);

//    // These three vertices become the first triangle.
//    mesh.addVertex(v0);
//    mesh.addVertex(v1);
//    mesh.addVertex(v2);
//
//    // These three vertices become the second triangle.
//    mesh.addVertex(v0);
//    mesh.addVertex(v2);
//    mesh.addVertex(v3);


    std::vector<glm::vec3> vertices =
    {
        v0, v1, v2, v3
    };
    
    mesh.addVertices(vertices);
    
//    mesh.addVertex(v0); // Index 0
//    mesh.addVertex(v1); // Index 1
//    mesh.addVertex(v2); // Index 2
//    mesh.addVertex(v3); // Index 3

//    // Our first triangle by index.
//    mesh.addIndex(0);
//    mesh.addIndex(1);
//    mesh.addIndex(2);
//
//    // Our second triangle by index.
//    mesh.addIndex(0);
//    mesh.addIndex(2);
//    mesh.addIndex(3);
    
    std::vector<ofIndexType> indices =
    {
        0, 1, 2, 0, 2, 3
    };
    
    mesh.addIndices(indices);
    
    mesh.draw();
    
    
}

