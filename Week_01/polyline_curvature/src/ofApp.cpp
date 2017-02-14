#include "ofApp.h"


void ofApp::setup()
{
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    //ofSetLogLevel(OF_LOG_VERBOSE);
    
    
    //perp *= 10.0f;
    //perp += points[0];
    //cout << points[0] << " pnt: " << perp << "<<" << endl;
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofBackground(0);
    
    ofSetColor(255,255,0,60);

    for (Circle c: circles)
        ofDrawCircle(c.center(), c.radius());

    ofSetColor(255,255,0);
    ofNoFill();
    ofBeginShape();
        for(int i = 0; i < points.size(); i++)
            ofCurveVertex(points[i].x, points[i].y);
    ofEndShape();
    
    ofSetColor(255);

    
    for (auto i = 1; i < points.size(); ++i)
    {
        ofDrawLine(points[i-1], points[i]);
        //ofVec2f dL = points[i-1] - points[i];
       // ofVec2f perp = points[i].getPerpendicular();
       // perp += points[i]; // translate
       // perp *= 15.0f; // scale in one dir
      //  ofLine(points[i], perp);
      //  perp *= -1.0f; // scale in the other dir
      //  ofLine(points[i], perp);

        ofVec2f dL = points[i-1] - points[i];
        
        ofVec2f perp0 = ofVec2f(-dL.y, dL.x);
        ofVec2f perp1 = ofVec2f(dL.y, -dL.x);
        
        perp0 /= dL.length();
        perp1 /= dL.length();
        
        perp0 *= 10.0;
        perp1 *= 10.0;
        
        perp0 += points[i-1];
        perp1 += points[i-1];
        
        ofDrawLine(perp0, perp1);
        
        //ofVec2f perp2 = dL.getPerpendicular();
        //perp2 += points[0];
        //perp2 *= -1;;
        
        //ofLine(points[0], perp2);
    }
    
    

    ofSetColor(0,255,0);

    int pointR = 4;

    for (auto i = 0; i < points.size(); ++i)
    {
        ofDrawCircle(-points[i].x - pointR/2.0f,
                     -points[i].y - pointR/2.0f,
                     pointR);
    }

    //for(int i = 0; i < points.size(); i++)
    //    ofDrawBitmapString(ofToString(points[i]), points[i]);  
}


void ofApp::keyPressed(int key)
{
    if(key == ' ')
    {
        circles.clear();
        points.clear();
    }

}


void ofApp::mouseDragged(int x, int y, int button)
{
    points.push_back(glm::vec2(x, y));
    auto i = points.size();

    Circle c;

    if (i > 2 && Circle::fromPoints(points[i-1], points[i-2], points[i-3], c))
    {
        circles.push_back(c);
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    points.push_back(glm::vec2(x, y));
    int i = points.size();
    
    Circle c;

    if (i > 2 && Circle::fromPoints(points[i-1], points[i-2], points[i-3], c))
    {
        circles.push_back(c);
    }
}
