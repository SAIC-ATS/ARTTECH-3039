#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    std::shared_ptr<ofPolyline> sharedPolyLineAtClassScopeFirst;
    std::shared_ptr<ofPolyline> sharedPolyLineAtClassScopeSecond;

    // std::unique_ptr<ofPolyline>
};
