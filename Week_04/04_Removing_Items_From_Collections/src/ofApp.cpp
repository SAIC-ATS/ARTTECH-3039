#include "ofApp.h"


void ofApp::setup()
{
    ofBuffer buffer = ofBufferFromFile("Food_Inspections_Short_Clean.csv");

    for (auto line: buffer.getLines())
    {
        int zip = ofToInt(line.substr(0, 5));
        std::string restaurant = line.substr(6);
        myMap[zip].push_back(restaurant);
    }

    auto it = myMap.begin();

    while (it != myMap.end())
    {
        if (it->first > 60618)
        {
            it = myMap.erase(it);
        }
        else
        {
            ++it;
        }
    }


    for (const auto& element: myMap)
    {
        std::cout << element.first << " count: " << element.second.size() << std::endl;
    }
}


void ofApp::update()
{
//    auto iter = myMap.find(60615);
//
//    if (iter != myMap.end())
//    {
//        // iter->first
//        for (const auto& rest: iter->second)
//        {
//            std::cout << rest << std::endl;
//        }
//    }
//
//    std::cout << "-----" << std::endl;
}


void ofApp::draw()
{
}
