//
// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    
    drawingArea.allocate(MNIST_WIDTH * DRAWING_SCALE,
                         MNIST_HEIGHT * DRAWING_SCALE,
                         GL_RGBA);

    drawingArea.begin();
    ofClear(0);
    drawingArea.end();
    
    for (std::size_t i = 0; i < 10; i++)
    {
        ofTexture tex;
        ofLoadImage(tex, "classes/" + ofToString(i) + ".png");
        targets.push_back(tex);
    }

    std::filesystem::create_directory(ofToDataPath("samples/", true));
}

void ofApp::update()
{
}


void ofApp::draw()
{
    ofSetColor(255);

    ofRectangle drawingAreaDisplay(10,
                                   10,
                                   drawingArea.getWidth(),
                                   drawingArea.getHeight());

    float x = ofGetMouseX() - drawingAreaDisplay.x;
    float y = ofGetMouseY() - drawingAreaDisplay.y;

    if (ofGetMousePressed())
    {
        drawingArea.begin();
        ofSetColor(255);
        ofFill();
        ofDrawCircle(x, y, brushRadius);
        drawingArea.end();
    }
    else if (drawingAreaDisplay.inside(ofGetMouseX(), ofGetMouseY()))
    {
        ofSetColor(255, 80);
        ofFill();
        ofDrawCircle(x + drawingAreaDisplay.x,
                     y + drawingAreaDisplay.y, brushRadius);
    }
    ofSetColor(255);
    drawingArea.draw(drawingAreaDisplay);
    
    ofNoFill();
    ofDrawRectangle(drawingAreaDisplay);
    
    ofFill();
    ofSetColor(255);
    targets[currentTarget].draw(10 + MNIST_WIDTH * DRAWING_SCALE, 10 + 0, MNIST_WIDTH * DRAWING_SCALE, MNIST_HEIGHT * DRAWING_SCALE);
    
    ofFill();
    ofSetColor(255);
    float xOffset = 10;
    float yOffset = 10 + MNIST_HEIGHT * DRAWING_SCALE;
    for (auto& entry: queuedForSave)
    {
        ofFill();
        ofSetColor(255);

        entry.second.draw(xOffset, yOffset);

        ofNoFill();
        ofSetColor(255, 255, 0);
        ofDrawRectangle(xOffset, yOffset, entry.second.getWidth(), entry.second.getHeight());
        
        if (yOffset + MNIST_WIDTH >= ofGetWidth())
        {
            yOffset += MNIST_HEIGHT;
            xOffset = 10;
        }
        else
        {
            xOffset += MNIST_WIDTH;
        }
    }
    
    std::stringstream ss;
    ss << " -/= : brush size" << std::endl;
    ss << "SPACE: queue image"  << std::endl;
    ss << "BKSP : delete last queued image"  << std::endl;
    ss << "   s : save to disk!"  << std::endl;

    ofSetColor(255);
    ofDrawBitmapString(ss.str(), 10, ofGetHeight() - 50);
}


void ofApp::keyPressed(int key)
{
    if (key == 'c')
    {
        drawingArea.begin();
        ofClear(0);
        drawingArea.end();
    }
    else if (key == '-')
    {
        brushRadius = std::max(1.0f, brushRadius - 1.0f);
    }
    else if (key == '=')
    {
        brushRadius = std::min(50.0f, brushRadius + 1.0f);
    }
    else if (key == ' ')
    {
        ofImage img;
        drawingArea.readToPixels(img.getPixels());
        img.resize(MNIST_WIDTH, MNIST_HEIGHT);
        queuedForSave.push_back({ currentTarget, img });
        currentTarget = std::size_t(ofRandom(targets.size()));
        
        drawingArea.begin();
        ofClear(0);
        drawingArea.end();

    }
    else if (key == OF_KEY_BACKSPACE)
    {
        if (!queuedForSave.empty())
        {
            queuedForSave.pop_back();
        }
    }
    else if (key == 's')
    {
        for (auto& entry: queuedForSave)
        {
            entry.second.save("samples/" + ofGetTimestampString() + "-" + ofToString(entry.first) + ".jpg");
        }
        
        queuedForSave.clear();
    }
}

