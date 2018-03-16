#include "ofApp.h"

void ofApp::setup(){

}

void ofApp::update(){

    if (needsCalculation)
    {
        cv::Rect rect(0, 0, ofGetWidth(), ofGetHeight());

        cv::Subdiv2D subdiv(rect);

        for (glm::vec2 point: points)
        {
            // Convert our point to  a cvPoint.
            cv::Point2f cvPoint(point.x, point.y);

            if (rect.contains(cvPoint))
            {
                subdiv.insert(cvPoint);
            }
        }

        mesh.clear();
        mesh.setMode(OF_PRIMITIVE_TRIANGLES);

        // Fill our triangle list with the triangulations
        std::vector<cv::Vec6f> triangleList;
        subdiv.getTriangleList(triangleList);

        for (std::size_t i = 0; i < triangleList.size(); ++i)
        {
            cv::Vec6f t = triangleList[i];

            cv::Point2f p1 = cv::Point(t[0], t[1]);
            cv::Point2f p2 = cv::Point(t[2], t[3]);
            cv::Point2f p3 = cv::Point(t[4], t[5]);

            if (rect.contains(p1) && rect.contains(p2) && rect.contains(p3))
            {
                mesh.addVertex({p1.x, p1.y, 0});
                mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                mesh.addVertex({p2.x, p2.y, 0});
                mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
                mesh.addVertex({p3.x, p3.y, 0});
                mesh.addColor(ofColor::fromHsb(ofRandom(255), 255, 255));
            }
        }

        needsCalculation = false;
    }

}

void ofApp::draw()
{
    ofSetColor(255);
    ofFill();
    mesh.draw();

    ofSetColor(0);
    ofFill();
    for (auto point: points)
    {
        ofDrawCircle(point, 5);
    }
}


void ofApp::keyPressed(int key)
{
    if (key == 'c')
    {
        points.clear();
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    points.push_back({ x, y });
    needsCalculation = true;
}


