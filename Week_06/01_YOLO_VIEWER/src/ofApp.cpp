#include "ofApp.h"

//    std::filesystem::directory_iterator iter(ofToDataPath("images/", true));
//    std::filesystem::directory_iterator end;
//
//    while (iter != end)
//    {
//        std::cout << iter->path().string() << std::endl;
//        ++iter;
//    }



void ofApp::setup()
{
    ofDirectory imageDir("images/");
    imageDir.allowExt("jpg");
    imageDir.allowExt("jpeg");
    imageDir.allowExt("png");
    imageDir.allowExt("gif");

    for (const ofFile& file: imageDir)
    {
        std::string imagePath = file.getAbsolutePath();
        std::string jsonPath = imagePath + ".yolo.json";

        ofJson json = ofLoadJson(jsonPath);

        data.push_back(std::make_pair(imagePath, json));
    }

    keyPressed(0);
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofSetColor(255);
    currentImage.draw(0, 0);

    ofJson json = data[imageIndex].second;

    for (ofJson det: json["dets"])
    {
        std::string label = det["label"];
        float prob = det["prob"];

        float x = det["rect"]["x"];
        float y = det["rect"]["y"];
        float w = det["rect"]["w"];
        float h = det["rect"]["h"];

        std::string displayString = label + " " + ofToString(prob);

        ofRectangle rect(x, y, w, h);

        ofNoFill();
        ofSetColor(255, 255, 0);
        ofDrawRectangle(rect);

        ofDrawBitmapStringHighlight(displayString, rect.x, rect.y);
    }
}

void ofApp::keyPressed(int key)
{
    imageIndex++;

    if (imageIndex >= data.size())
    {
        imageIndex = 0;
    }

    currentImage.load(data[imageIndex].first);
}














