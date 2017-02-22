#include "ofApp.h"
#include "ofxPS3EyeGrabber.h"


void ofApp::setup()
{
    camera.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    camera.setDesiredFrameRate(30);
    camera.setup(640, 480);

    // Pre-allocate some memory.
    frames.reserve(8192);
}

void ofApp::update()
{
    camera.update();

    if (camera.isFrameNew() && isRecording)
  {
        frames.push_back(camera.getPixels());
    }
}

void ofApp::draw()
{
    camera.draw(0,0);

    if (isRecording)
    {
        ofDrawBitmapStringHighlight("# Frames: " + ofToString(frames.size()), 20, 20, ofColor::red);
    }
}


void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        if (isRecording)
        {
            std::string templateFilename = ofGetTimestampString() + "/FRAME_{FRAME_NUMBER}.png";

            for (auto i = 0; i < frames.size(); ++i)
            {
                auto filename = templateFilename;
                ofStringReplace(filename, "{FRAME_NUMBER}", ofToString(i, 4, '0'));
                ofSaveImage(frames[i], filename);
            }
        }
        else
        {
            frames.clear();
            frames.reserve(8192);
        }

        isRecording = !isRecording;
    }
}
