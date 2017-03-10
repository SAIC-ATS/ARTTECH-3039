#include "ofApp.h"


void ofApp::setup()
{
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(3);
    myVector.push_back(3);

    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(3);
    mySet.insert(2);
    mySet.insert(3);

    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;
    myMap["four"] = 4;
    myMap["five"] = 5;
    myMap["five"] = 9999;
    myMap["seven (haha)"] = 6;

    std::pair<std::string, int> myPair = std::make_pair("fifty-five", 55);

    myMap.insert(myPair);

    for (const auto& element: myVector)
    {
        std::cout << element << std::endl;
    }

    std::cout << "Those were the vector values." << std::endl;

    for (const auto& element: mySet)
    {
        std::cout << element << std::endl;
    }

    std::cout << "Those were the sets values." << std::endl;


    for (const std::pair<std::string, int>& thePair: myMap)
    {
        std::cout << "Key: " << thePair.first << " Value: " << thePair.second << std::endl;
    }

    std::cout << "Those were the map values." << std::endl;

    myMapOfVectors["hello"].push_back(5);
    myMapOfVectors["hello"].push_back(4);
    myMapOfVectors["hello"].push_back(2);

    myMapOfVectors["goodbye"].push_back(999);
    myMapOfVectors["goodbye"].push_back(222);
    myMapOfVectors["goodbye"].push_back(223);

    myMapOfVectors["aaaaaaaaaaaa"] = { 3, 4, 5, 6, 7, 8, 1000, -1 };

    for(const auto& thePair: myMapOfVectors)
    {
        std::cout << "Key: " << thePair.first << std::endl;;

        for (const auto& theElement: thePair.second)
        {
            std::cout << "\t" << theElement << std::endl;
        }
    }
}


void ofApp::update()
{
}


void ofApp::draw()
{
}
