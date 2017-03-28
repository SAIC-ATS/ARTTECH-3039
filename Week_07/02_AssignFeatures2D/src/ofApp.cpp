#include "ofApp.h"


void ofApp::setup()
{
    ofxAssignment solver;

    ofJson settings = ofLoadJson("settings.json");

    int nx = settings["assignment"]["nx"];
    int ny = settings["assignment"]["ny"];
    int w = settings["assignment"]["w"];
    int h = settings["assignment"]["h"];
    int displayW = settings["assignment"]["display_w"];
    int displayH = settings["assignment"]["display_h"];

    std::string imageSavePath = settings["image_save_path"];

    std::string embeddingsListFile = settings["embedded_image_list"];

    ofJson embeddings = ofLoadJson(embeddingsListFile);

    std::vector<std::string> imageFiles;
    std::vector<ofVec2f> tsnePoints;

    for (auto& embedding: embeddings)
    {
        imageFiles.push_back(embedding["image_file"]);
        tsnePoints.push_back(ofVec2f(embedding["x"], embedding["y"]));
    }

    std::vector<ofVec2f> solvedGrid;
    std::vector<ofVec2f> gridPoints = makeGrid(nx, ny);
    solvedGrid = solver.match(tsnePoints, gridPoints, false);

    // Save an image.

    ofFbo fbo;
    fbo.allocate(nx * displayW, ny * displayH);
    fbo.begin();
    ofClear(0, 0);
    ofBackground(0);
    for (int i=0; i<solvedGrid.size(); i++) {
        ofImage image;
        if (ofLoadImage(image, imageFiles[i]))
        {
            image.update();
            float x = (fbo.getWidth() - displayW) * solvedGrid[i].x;
            float y = (fbo.getHeight() - displayH) * solvedGrid[i].y;
            image.draw(x, y, displayW, displayH);
        }
        else
        {
            ofLogError() << "Unable to load: " << imageFiles[i];
        }
    }
    fbo.end();
    ofImage img;
    fbo.readToPixels(img);
    img.save(imageSavePath);

    ofExit();
}


