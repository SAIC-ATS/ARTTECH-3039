#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

    angle += 0.003;

}

void ofApp::draw(){
    ofBackground(0);

//    ofSetColor(255);
//    ofNoFill();
//    for (auto point: polyline)
//    {
//        ofDrawCircle(point, 10);
//    }
//
//    polyline.draw();
//
//    ofSetColor(0, 255, 0);
//    ofNoFill();
//    for (auto point: resampledPolyline)
//    {
//         ofDrawCircle(point, 20);
//    }




    for (std::size_t i = 0; i < resampledPolyline.size(); ++i)
    {
        auto currentPoint = resampledPolyline[i];
        auto normalPoint = resampledPolyline.getNormalAtIndex(i);
        auto tangentPoint = resampledPolyline.getTangentAtIndex(i);

        float scale = ofMap(i + angle, 0, resampledPolyline.size(), 0, TWO_PI);

        scale = 100 * sin(100 * scale); // value between -1 to 1.

        auto normalPlus = currentPoint + (normalPoint * scale);
        auto normalMinus = currentPoint - (normalPoint * scale);

        ofSetColor(255, 255, 0);
        ofDrawLine(currentPoint, normalPlus);

        ofSetColor(255, 0, 0);
        ofDrawLine(currentPoint, normalMinus);

        auto tangentPlus = currentPoint + (tangentPoint * scale);
        auto tangentMinus = currentPoint - (tangentPoint * scale);

        ofSetColor(0, 255, 255);
        ofDrawLine(currentPoint, tangentPlus);

        ofSetColor(0, 0, 255);
        ofDrawLine(currentPoint, tangentMinus);

    }


    float position = sin(angle); // value between -1 to 1.
    float position2 = sin(angle*10); // value between -1 to 1.

    position = ofMap(position, -1, 1, 0, 1);

    auto polylinePosition = resampledPolyline.getPointAtPercent(position);

    float index = resampledPolyline.getIndexAtPercent(position);

    auto normalPosition = resampledPolyline.getNormalAtIndexInterpolated(index);

    auto normalPlus = polylinePosition + (normalPosition * 20 * position2);
//    auto normalMinus = currentPoint - (normalPoint * scale);

    ofDrawCircle(normalPlus, 20);

//    ofSetColor(255);
//    resampledPolyline.draw();
}

void ofApp::mouseDragged(int x, int y, int button){
    polyline.addVertex(x, y);
}

void ofApp::mousePressed(int x, int y, int button){
    polyline.clear();
    polyline.addVertex(x, y);
}

void ofApp::mouseReleased(int x, int y, int button){
    angle = 0;
    polyline.addVertex(x, y);
     resampledPolyline = polyline.getResampledBySpacing(5);
//    resampledPolyline = polyline.getResampledByCount(1);

}



























