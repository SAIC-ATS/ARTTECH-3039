#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    
    ofLoadImage(texture, "puppy.jpg");
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
    
    std::vector<glm::vec2> textureCoordinates = {
        glm::vec2(0, 0),
        glm::vec2(texture.getWidth(), 0),
        glm::vec2(texture.getWidth(), texture.getHeight()),
        glm::vec2(0, texture.getHeight())
    };
    
    mesh.addVertices(vertices);
    mesh.addTexCoords(textureCoordinates);

    //mesh.addColors(colors);
    
    std::vector<ofIndexType> indices =
    {
        0, 1, 2,
        0, 2, 3
    };

    mesh.addIndices(indices);
    

    // Set texture as the "active" / "bound" texture.
    texture.bind();

    // Draw the mesh.  The texture coordinates added will refer to the "bound" texture.
    mesh.draw();
    
    // Disable the "active" / "bound" texture.
    texture.unbind();
    
    
}

