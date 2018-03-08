#include "ofApp.h"


void ofApp::setup()
{

    ofDirectory dir("");
    dir.allowExt("png");

    std::filesystem::path testing(ofToDataPath("testing/", true));
    std::filesystem::path training(ofToDataPath("training/", true));

    ofDirectory(testing).create();
    ofDirectory(training).create();

    for (ofFile file: dir)
    {
        if (ofRandom(1) > 0.90)
        {
            file.moveTo(testing);
        }
        else
        {
            file.moveTo(training);
        }

    }

    ofExit();
}
