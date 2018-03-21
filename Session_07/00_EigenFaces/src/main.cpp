#include "ofApp.h"


int main()
{
    ofSetupOpenGL(1246, 654, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
