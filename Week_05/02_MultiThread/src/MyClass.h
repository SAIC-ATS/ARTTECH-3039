#pragma once


#include "ofMain.h"


class MyClass: public ofThread
{
public:
    float getDifficultInt() const;

    void threadedFunction() override;

    ofThreadChannel<float> channel;

};
