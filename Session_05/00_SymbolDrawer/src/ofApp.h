//
// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;

    ofFbo drawingArea;
    float brushRadius = 15;

    std::size_t currentTarget = 0;
    std::vector<ofTexture> targets;
    
    std::vector<std::pair<std::size_t, ofImage>> queuedForSave;
    
    enum
    {
        MNIST_WIDTH = 28,
        MNIST_HEIGHT = 28,
        DRAWING_SCALE = 10
    };
};
