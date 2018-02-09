#include "ofApp.h"


void ofApp::setup()
{
    std::vector<std::string> myStrings = { "Hello", "there", "I", "Am", "Here" };
    std::vector<int> myInts= { 1, 2, 3, 4, 5 };

    for (std::size_t i = 0; i < myStrings.size(); i++)
    {
        std::string theString = myStrings[i];
        int myInt = myInts[i];
        std::cout << theString << " " << << std::endl;
        //myStrings[i] = "blah";
    }


    for (auto theString: myStrings)
    {
        if (theString[1] == 'e')
        {

        }
// std::cout << theString[1] << std::endl;
        theString = "super bloah";
    }


    for (std::string theString: myStrings)
    {
        std::cout << theString << std::endl;
    }


//    for (auto theString: myStrings)
//    {
//        std::cout << theString << std::endl;
//    }

    std::map<std::string, double> myMap {{ "Hi", 99 }, {"Low", -100 }};

    std::map<std::string, std::vector<std::pair<std::vector<int>, double>>> crazyMap;

    //std::map<std::string, std::vector<std::pair<std::vector<int>, double>>>::iterator iter = crazyMap.begin();

    auto iter = crazyMap.begin();

//        for (std::pair<std::string, std::vector<std::pair<std::vector<int>, double>>> entry: myMap)
//        {

//        }


    for (auto& entry: myMap)
    {

    }


//    for (std::pair<std::string, int> entry: myMap)
//    {
//        std::cout << entry.first << " -> " << entry.second << std::endl;
//    }

//    for (auto entry: myMap)
//    {
//        std::cout << entry.first << " -> " << entry.second << std::endl;
//    }

    ofExit();
}

