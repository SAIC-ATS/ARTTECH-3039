#include "ofApp.h"


void ofApp::setup()
{
    myColors.push_back(ofColor(255, 0, 0));
    myColors.push_back(ofColor::teal);
    myColors.push_back(ofColor::fromHsb(127, 255, 255));
    myColors.push_back(ofColor(255, 255, 0));
}


void ofApp::draw()
{
    float x = 0;
    
    // i++ -> i+=1 -> i = i + 1 (all the same thing)
    
    // Using a for loop to "iterate through my collection of colors"
    for (int i = 0; i < myColors.size(); i++)
    {
        ofSetColor(myColors[i]);
        ofDrawRectangle(x, 0, 100, 100);
        x = x + 100;
    }
}


void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_BACKSPACE)
    {
        if (myColors.size() > 0)
        {
            // Delete the zero-th element of the array.
            myColors.erase(myColors.begin());

            // Delete the last element
            // myColors.erase(myColors.end() - 1);
            
            // Delete the index 4
            // You MUST make sure that the element exists before you try to delete it.
            // if (myCn > 4) {
            //     myColors.erase(myColors.begin() + 4);
            // }
        }
    }
    else if (key == 'n')
    {
        myColors.push_back(ofColor::fromHsb(ofRandom(255), 255, 255));
    }
}

