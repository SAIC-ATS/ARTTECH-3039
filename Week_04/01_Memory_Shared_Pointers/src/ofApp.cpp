#include "ofApp.h"


void ofApp::setup()
{
    // sharedPolyLineAtClassScopeFirst = std::shared_ptr<ofPolyline>(new ofPolyline());

    sharedPolyLineAtClassScopeFirst = std::make_shared<ofPolyline>();

    sharedPolyLineAtClassScopeFirst->addVertex(0, 0);
    sharedPolyLineAtClassScopeFirst->addVertex(ofGetWidth(), ofGetHeight());
    sharedPolyLineAtClassScopeFirst->addVertex(0, ofGetHeight());

    std::cout << sharedPolyLineAtClassScopeFirst.use_count() << std::endl;

    sharedPolyLineAtClassScopeSecond = sharedPolyLineAtClassScopeFirst;

    std::cout << sharedPolyLineAtClassScopeFirst.use_count() << std::endl;

    std::shared_ptr<ofPolyline> sharedPolyLineAtClassScopeThird = sharedPolyLineAtClassScopeSecond;

    std::cout << sharedPolyLineAtClassScopeFirst.use_count() << std::endl;

    sharedPolyLineAtClassScopeSecond;


    // std::unique_ptr<ofPolyline> a = std::make_unique<ofPolyline>();
    // std::unique_ptr<ofPolyline> b = std::move(a);

}


void ofApp::update()
{
    std::cout << sharedPolyLineAtClassScopeFirst.use_count() << std::endl;
}


void ofApp::draw()
{
    sharedPolyLineAtClassScopeFirst->draw();

    // sharedPolyLineAtClassScopeSecond->draw();
}
