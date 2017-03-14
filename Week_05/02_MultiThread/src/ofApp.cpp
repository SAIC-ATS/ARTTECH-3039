#include "ofApp.h"


void ofApp::setup()
{
    for (int i = 0; i < 10; ++i)
    {
        myClasses.push_back(std::make_shared<MyClass>());
        myClasses.back()->startThread();
    }
}


void ofApp::update()
{
    for (int i = 0; i < myClasses.size(); ++i)
    {
        float myNum = 0;
        if (myClasses[i]->channel.tryReceive(myNum))
        {
            std::cout << "Got a  magic number! " << myNum << " from thread number " << i << std::endl;
        }
    }
}


void ofApp::draw()
{
    ofBackground(brightness);

    brightness++;

    if (brightness > 255) brightness = 0;
}


void ofApp::exit()
{
    for (auto& t: myClasses)
    {
        t->stopThread();
        t->waitForThread();
    }
}