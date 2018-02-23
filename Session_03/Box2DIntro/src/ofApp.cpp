#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createGround();
    // box2d.createBounds(...)
    box2d.setFPS(30);

    ofLoadImage(tex, "ds.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();

    if (ofGetFrameNum() % 5 == 0)
    {
        auto circle = std::make_shared<ofxBox2dCircle>();
        circle->setPhysics(0.3, 0.5, 0.1);
        circle->setup(box2d.getWorld(), ofRandom(ofGetWidth()), 15, ofRandom(10, 30));
        circles.push_back(circle);

        auto rectangle = std::make_shared<ofxBox2dRect>();
        rectangle->setPhysics(0.3, 0.5, 0.1);
        rectangle->setup(box2d.getWorld(), ofRandom(ofGetWidth()), 15, ofRandom(10, 30), ofRandom(10, 30));
        rectangles.push_back(rectangle);
    }


    ofRemove(circles, [&](std::shared_ptr<ofxBox2dCircle> circle)
    {
        return !ofRectangle(0, 0, ofGetWidth(), ofGetHeight()).inside(circle->getPosition());
    });

    ofRemove(rectangles, [&](std::shared_ptr<ofxBox2dRect> rectangle)
    {
        return !ofRectangle(0, 0, ofGetWidth(), ofGetHeight()).inside(rectangle->getPosition());
    });

    ofRemove(polys, [&](std::shared_ptr<ofxBox2dPolygon> poly)
    {
        return !ofRectangle(0, 0, ofGetWidth(), ofGetHeight()).inside(poly->getPosition());
    });

}

//--------------------------------------------------------------
void ofApp::draw(){
    polyline.draw();

    for (auto circle: circles)
    {
         circle->draw();
        auto p = circle->getPosition();

        ofPushMatrix();
        ofTranslate(p);
        ofRotateDeg(circle->getRotation());

        float width = circle->getRadius() * 2;
        float height = width;
        float x = - width / 2;
        float y = - height / 2;

        tex.draw(x, y, width, height);
        ofPopMatrix();
    }

    for (auto rectangle: rectangles)
    {
        rectangle->draw();
    }

    for (auto poly: polys)
    {
        poly->draw();
    }

    ofDrawBitmapStringHighlight("#Circles: " + ofToString(circles.size()), 20, 20);
}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    polyline.addVertex({x, y, 0});
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    polyline.clear();
    polyline.addVertex({x, y, 0});
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    polyline.addVertex({x, y, 0});
    polyline.simplify();

    auto poly = std::make_shared<ofxBox2dPolygon>();
    poly->addVertices(polyline);
    poly->setPhysics(1.0, 0.3, 0.3);
    poly->triangulatePoly();
    poly->create(box2d.getWorld());
    polys.push_back(poly);
}

