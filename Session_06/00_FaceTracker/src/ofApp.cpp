#include "ofApp.h"


void ofApp::setup()
{
    // Setup grabber
    grabber.setup(1280,720);
    
    // Setup tracker
    tracker.setup();
}


void ofApp::update()
{
    grabber.update();
    
    // Update tracker when there are new frames.
    if (grabber.isFrameNew())
    {
        tracker.update(grabber);

        if (tracker.size() > 0)
        {
            auto& instances = tracker.getInstances();

            // Get the first face that it found.
            auto& instance = instances[0];

            // Get the landmarks for the instance.
            auto& landmarks = instance.getLandmarks();

            // Get the left and right eyes.
            leftEye = landmarks.getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
            rightEye = landmarks.getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);

            leftEyeMesh = getMeshForFeature(leftEye);
            rightEyeMesh = getMeshForFeature(rightEye);
        }
        else
        {
            leftEye.clear();
            rightEye.clear();

            leftEyeMesh.clear();
            rightEyeMesh.clear();
        }
    }
}


void ofApp::draw()
{
// Draw camera image
//    grabber.draw(0, 0);

//    leftEye.draw();
//    rightEye.draw();

//    for (auto& p: leftEye) ofDrawCircle(p, 4);
//    for (auto& p: rightEye) ofDrawCircle(p, 4);

    ofSetColor(255);
    ofFill();
    grabber.bind();
    leftEyeMesh.draw();
    rightEyeMesh.draw();
    grabber.unbind();
}


ofMesh ofApp::getMeshForFeature(const ofPolyline& poly)
{
    ofMesh mesh;

    cv::Rect rect(0, 0, ofGetWidth(), ofGetHeight());

    cv::Subdiv2D subdiv(rect);

    for (auto& point: poly)
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
            mesh.addVertex({p2.x, p2.y, 0});
            mesh.addVertex({p3.x, p3.y, 0});

            mesh.addTexCoord({p1.x, p1.y});
            mesh.addTexCoord({p2.x, p2.y});
            mesh.addTexCoord({p3.x, p3.y});
        }
    }

    return mesh;
}

