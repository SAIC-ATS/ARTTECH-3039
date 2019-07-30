#include "ofApp.h"


int main()
{
    ofSetupOpenGL(100, 100, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
