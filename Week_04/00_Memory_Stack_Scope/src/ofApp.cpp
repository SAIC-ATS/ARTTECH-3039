#include "ofApp.h"


void ofApp::setup()
{
    polyLineAtClassScope.addVertex(0, 0);
    polyLineAtClassScope.addVertex(ofGetWidth(), ofGetHeight());
    polyLineAtClassScope.addVertex(0, ofGetHeight());

    ofPolyline polylineOnStack;
    polylineOnStack.addVertex(0, 0);
    polylineOnStack.addVertex(ofGetWidth(), ofGetHeight());
    polylineOnStack.addVertex(0, ofGetHeight());
    // polylineOnStack will be deallocated after it leaves this scope.


    int i = 99;

    for (int i = 0; i < 33; i++)
    {
        std::cout << i << std::endl;
    }

    {
        int i = 108;
        std::cout << i << std::endl;
    }

    std::cout << i << std::endl;

    {
        i = 999;
    }

    std::cout << i << std::endl;
}


void ofApp::update()
{
}


void ofApp::draw()
{
    polyLineAtClassScope.draw();

    // This won't work because it is out of scope.
    // polylineOnStack.draw();

}
