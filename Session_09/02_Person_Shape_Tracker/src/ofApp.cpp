#include "ofApp.h"


void ofApp::setup()
{
    ofxDlib::FaceTracker::Settings settings;
    // settings.faceDetectorSettings.inputROI = ofRectangle(0, 0, 600, 720);

    tracker.setup(settings);

    tracker.registerEvents(this);

    video.setDeviceID(0);
    video.setup(1280, 720);
}


void ofApp::update()
{
    video.update();

    if (video.isFrameNew())
    {
        std::size_t frameId = tracker.track(video);

        if (frameId > 0)
        {
            ofTexture frame;
            frame.loadData(video.getPixels());
            frameHistory[frameId] = frame;
        }
    }
}


void ofApp::draw()
{
    ofSetColor(ofColor::white);
    // video.draw(0, 0);

    for (auto& entry: database)
    {
        // My id is @ entry.first
        // Person for this id is @ entry.second
        ofSetColor(entry.second.color);

        for (std::size_t i = 0; i < entry.second.meshes.size(); ++i)
        {
            ofSetColor(ofColor::white);
            entry.second.textures[i].bind();
            entry.second.meshes[i].draw();
            entry.second.textures[i].unbind();
        }


        for (auto shape: entry.second.faceShapes)
        {
            ofPolyline mouth = shape.getFeatureAsPolyline(ofxDlib::FaceShape::OUTER_MOUTH);
            mouth.draw();
        }
    }
}


void ofApp::onTrackBegin(ofxDlib::FaceTrackerEventArgs& evt)
{
    Person person;
    // Give this person a unique color.
    person.color = ofColor::fromHsb(ofRandom(255), 255, 255);
    person.faceShapes.push_back(evt.faceShape);

    ofTexture frame = frameHistory[evt.frameId];
    person.textures.push_back(frame);

    // And empty mesh, a placeholder.
    person.meshes.push_back(ofMesh());

    // Put the person in our database.
    database[evt.label] = person;
}


void ofApp::onTrackUpdate(ofxDlib::FaceTrackerEventArgs& evt)
{
    database[evt.label].faceShapes.push_back(evt.faceShape);
    ofTexture frame = frameHistory[evt.frameId];
    database[evt.label].textures.push_back(frame);

    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    auto leftEyeCoordinates = evt.faceShape.getFeature(ofxDlib::FaceShape::LEFT_EYE);

    for (auto vertex: leftEyeCoordinates)
    {
        glm::vec3 v3(vertex.x, vertex.y, 0);
        mesh.addVertex(v3);
        mesh.addTexCoord(vertex);
        mesh.addColor(ofColor::white);
    }

    std::vector<ofIndexType> indices = {
        0, 1, 5,
        1, 2, 5,
        2, 4, 5,
        2, 3, 4
    };

    mesh.addIndices(indices);

    database[evt.label].meshes.push_back(mesh);

//    // Remove all old faces so that we never exceed 100 faceshapes in our history.
//    while (database[evt.label].faceShapes.size() > 100)
//    {
//        database[evt.label].faceShapes.erase(database[evt.label].faceShapes.begin());
//    }
}


void ofApp::onTrackEnd(ofxDlib::FaceTrackerEventArgs& evt)
{
    database.erase(database.find(evt.label));
}
