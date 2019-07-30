#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
}


void ofApp::draw()
{
    myPolyline.draw();
    
    for (int i = 0; i < myPolyline.size(); i++)
    {
        float vertexX = myPolyline[i].x;
        float vertexY = myPolyline[i].y;
        
        ofDrawCircle(vertexX, vertexY, 5);
    }
}


void ofApp::keyPressed(int key)
{
    std::cout << "The " << key << " was pressed." << std::endl;
}


void ofApp::mouseDragged(int x, int y, int button)
{
    myPolyline.addVertex(x, y);
}


void ofApp::mousePressed(int x, int y, int button)
{
    myPolyline.clear();
    myPolyline.addVertex(x, y);
}
