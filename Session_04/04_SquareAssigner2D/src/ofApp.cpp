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
    int PROJECTED_FEATURE_DIMENSIONS = 2;
    float PERPLEXITY = 40;
    float THETA = 0.2;
    bool NORMALIZE = true;

    // We want to get a 1000 x 2 vector of vectors back from tsne.
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
                                             float(tsnePoints[i][1]) };


            initial.push_back(ofVec2f(squares[i].featureProjection[0],
                                      squares[i].featureProjection[1]));
        }
    }


    for (std::size_t x = 0; x < 50; x++)
    {
        for (std::size_t y = 0; y < 20; y++)
        {
            grid.push_back(ofVec2f(x / 50.0, y / 20.0));
        }
    }

    // Solve it!
    grid = solver.match(initial, grid);
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofBackground(255);
    for (std::size_t i = 0; i < squares.size(); i++)
    {

        float drawLocationX = ofMap(grid[i].x, 0, 1, 0, ofGetWidth());
        float drawLocationY = ofMap(grid[i].y, 0, 1, 0, ofGetHeight());

        squares[i].tex.draw(drawLocationX, drawLocationY);
    }
}
