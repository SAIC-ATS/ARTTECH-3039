#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(255);
    ofSetCircleResolution(64);
}

void ofApp::update(){

    if (needsCalculation)
    {
        circles.clear();
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

                Circle c;
                if (Circle::fromPoints({p1.x, p1.y},
                                       {p2.x, p2.y},
                                       {p3.x, p3.y}, c))
                {
                    circles.push_back(c);
                }

            }
        }

        // Get our Voroni Data.
        std::vector<std::vector<cv::Point2f>> facets;
        std::vector<cv::Point2f> centers;

        // Fill our facests and centers with Voroni data.
        subdiv.getVoronoiFacetList(std::vector<int>(), facets, centers);

        vFacets.clear();
        for (auto facet: facets)
        {
            ofPath path;
            path.setColor(ofColor::fromHsb(ofRandom(255), 255, 255, 80));
            for (std::size_t i = 0; i <  facet.size(); ++i)
            {
                path.lineTo({facet[i].x, facet[i].y, 0});
            }

            vFacets.push_back(path);
        }

        vCenters.clear();
        for (cv::Point2f center: centers)
        {
            vCenters.push_back({ center.x, center.y });
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

    ofFill();
    ofSetColor(255);
    for (auto path: vFacets)
    {
        path.draw();
    }

    ofSetColor(255, 255, 0);
    ofFill();
    for (auto point: vCenters)
    {
        ofDrawCircle(point, 5);
    }

    ofSetColor(255, 175);
    ofNoFill();
    for (auto circle: circles)
    {
        ofDrawCircle(circle.center(), circle.radius());
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


