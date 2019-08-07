#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    
    ofLoadImage(pixels, "puppy.jpg");
    texture.loadData(pixels);
    
    
    // Create the mesh.
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    std::size_t meshRows = pixels.getHeight();
    std::size_t meshCols = pixels.getWidth();

    float meshWidth = pixels.getWidth();
    float meshHeight = pixels.getHeight();

    
    // First, generate the vertices.
    for (std::size_t row = 0; row < meshRows; row++)
    {
        for (std::size_t col = 0; col < meshCols; col++)
        {
            // Sample the color from the RGB image.
            std::size_t colorX = ofMap(col, 0, meshCols, 0, pixels.getWidth());
            std::size_t colorY = ofMap(row, 0, meshRows, 0, pixels.getHeight());
            
            ofColor color = pixels.getColor(colorX, colorY);
            mesh.addColor(color);

            // 3D Positions in space.

            float saturation = color.getSaturation();
            
            float x = ofMap(col, 0, meshCols, -meshWidth/2, meshWidth/2);
            float y = ofMap(row, 0, meshRows, -meshHeight/2, meshHeight/2);
            float z = ofMap(saturation, 0, 255, -200, 200);
            glm::vec3 position = { x, y, z };
            mesh.addVertex(position);
            
        }
    }
    
    // Second create indices.
    // First, generate the vertices.
    for (std::size_t col = 0; col < meshCols; col++)
    {
        for (std::size_t row = 0; row < meshRows; row++)
        {
            if (col < (meshCols - 1) && row < (meshRows - 1))
            {
                // This is when I will make indices.
                ofIndexType currentIndex   = (row    ) * meshCols + (col    );
                ofIndexType eastIndex      = (row    ) * meshCols + (col + 1);
                ofIndexType southEastIndex = (row + 1) * meshCols + (col + 1);
                ofIndexType southIndex     = (row + 1) * meshCols + (col    );

                glm::vec3 currentPosition = mesh.getVertices()[currentIndex];
                glm::vec3 eastPosition = mesh.getVertices()[eastIndex];
                glm::vec3 southPosition = mesh.getVertices()[southIndex];

                if (currentPosition.z < 0)
                {
                    if (glm::distance(currentPosition, eastPosition) < 5)
                    {
                        // Triangle 0
                        mesh.addIndex(currentIndex);
                        mesh.addIndex(eastIndex);
                        mesh.addIndex(southEastIndex);
                    }

                    if (glm::distance(currentPosition, southPosition) < 5)
                    {
                        // Triangle 1
                        mesh.addIndex(currentIndex);
                        mesh.addIndex(southEastIndex);
                        mesh.addIndex(southIndex);
                    }
                }
            }
        }
    }
}


void ofApp::update()
{
}


void ofApp::draw()
{
    texture.draw(0, 0);

    ofEnableDepthTest();
    cam.begin();
    mesh.draw();
    cam.end();
    ofDisableDepthTest();
}

