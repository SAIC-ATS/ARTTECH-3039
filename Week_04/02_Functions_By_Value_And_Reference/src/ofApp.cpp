#include "ofApp.h"


void ofApp::setup()
{
    const int i = 0;

    // Not allowed because we marked int as const.
    // i = 99;

    int myInt = 1;

    myFuncPassedByValue(myInt);

    std::cout << "myInt was not changed ... see -> " << myInt << std::endl;

    myFuncPassedByReference(myInt);

    std::cout << "myInt WAS INDEED changed ... see -> " << myInt << std::endl;

}


void ofApp::update()
{
}


void ofApp::draw()
{
}


void ofApp::myFuncPassedByValue(int i)
{
    // i is actually a copy of the value passed ...
    // passing by value makes a copy of the passed value into i and it works with the copy, not the original.
    i = i + 99;
    std::cout << i << std::endl;
}



void ofApp::myFuncPassedByReference(int& i)
{
    // this does NOT make a copy, you are modifying the original that is referenced by i.
    i = i + 99;
    std::cout << i << std::endl;
}


void ofApp::myFuncPassedByConstReference(const int& i)
{
    // we can't modify it because it is a const reference and no copy was made.
    // i = i + 99;

    // We can do other things with i as long as they don't change i itself.
    int myI = i;
    myI = myI + 99;
    int yourI = 99 + i;

    std::cout << i << std::endl;
}
