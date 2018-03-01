#include "ofApp.h"


void ofApp::setup()
{
    ofJson json = ofLoadJson("squares.json");

    for (auto jsonSquare: json)
    {
        Square square;
        // Load the filename into the square object.
        ofLoadImage(square.tex, jsonSquare["filename"].get<std::string>());

        // Make a feature vector out of our various features.
        square.features.push_back(jsonSquare["x"]); // 0
        square.features.push_back(jsonSquare["y"]); // 1
        square.features.push_back(jsonSquare["width"]); // 2
        square.features.push_back(jsonSquare["height"]); // 3
        square.features.push_back(jsonSquare["red"]); // 4
        square.features.push_back(jsonSquare["green"]); // 5
        square.features.push_back(jsonSquare["blue"]); // 6

        squares.push_back(square);
    }
    // PCA
    // TSNE

    std::vector<std::vector<float>> allFeatures;

    // We create a 1000 x 7 vector of vectors
    for (auto square: squares)
    {
        allFeatures.push_back(square.features);
    }

    int NUM_POINTS = 1000;
    int FEATURE_DIMENSIONS = 7;
    int PROJECTED_FEATURE_DIMENSIONS = 3;
    float PERPLEXITY = 40;
    float THETA = 0.2;
    bool NORMALIZE = true;

    // We want to get a 1000 x 3 vector of vectors back from tsne.
    tsnePoints = tsne.run(allFeatures,
                          PROJECTED_FEATURE_DIMENSIONS,
                          PERPLEXITY,
                          THETA,
                          NORMALIZE,
                          runManually);

    if (!runManually)
    {
        for (std::size_t i = 0; i < tsnePoints.size(); ++i)
        {
            squares[i].featureProjection = { float(tsnePoints[i][0]),
                                             float(tsnePoints[i][1]),
                                             float(tsnePoints[i][2])
                                           };
        }
    }

}


void ofApp::update()
{
    if (runManually)
    {
        tsnePoints = tsne.iterate();

        for (std::size_t i = 0; i < tsnePoints.size(); ++i)
        {
            squares[i].featureProjection = { float(tsnePoints[i][0]),
                                             float(tsnePoints[i][1]),
                                             float(tsnePoints[i][2])
                                           };
        }
    }
}


void ofApp::draw()
{
    ofBackground(255);
    ofEnableDepthTest();

    cam.begin();

    for (auto square: squares)
    {
        float drawLocationX = ofMap(square.featureProjection[0], 0, 1, -500, 500);
        float drawLocationY = ofMap(square.featureProjection[1], 0, 1, -500, 500);
        float drawLocationZ = ofMap(square.featureProjection[2], 0, 1, -500, 500);

        square.tex.draw(drawLocationX, drawLocationY, drawLocationZ);
    }

    cam.end();

    ofDisableDepthTest();
}
