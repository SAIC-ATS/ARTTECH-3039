#include "ofApp.h"


void ofApp::setup()
{
    float w = 640;
    float h = 480;

    std::size_t nRows = 20;
    std::size_t nCols = 20;

    for (std::size_t iy = 0; iy < nRows;  iy++)
    {
        for (std::size_t ix = 0; ix < nCols;  ix++)
        {
            mesh.addVertex({w / nRows * ix, w / nRows * iy, 0});
            mesh.addColor(ofFloatColor::fromHsb(ofRandom(1), 1, 1));
        }
    }

    // index = y * numCols + x;


    for (int y = 0; y < nRows - 1; y++)
    {
        for (int x = 0; x < nCols - 1; x++)
        {
            mesh.addIndex((y + 0) * nCols + (x + 0));
            mesh.addIndex((y + 0) * nCols + (x + 1));
            mesh.addIndex((y + 1) * nCols + (x + 0));


            mesh.addIndex((y + 0) * nCols + (x + 1)

            mesh.addIndex((y+1) * nCols + x + 1);
            mesh.addIndex((y+1) * nCols + x);

        }
    }

}


void ofApp::draw()
{
    cam.begin();
    mesh.draw();
    cam.end();
}


