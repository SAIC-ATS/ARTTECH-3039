#include "ofApp.h"


void ofApp::setup()
{
    loadData();
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofBackground(0);

    for (const auto& polyline: strokes)
    {
        polyline.draw();
    }
}

void ofApp::exit()
{
    saveData();
}


void ofApp::keyPressed(int key)
{
    if (key == 's')
    {
        saveData();
    }
}


void ofApp::mouseDragged(int x, int y, int button)
{
    // Add the current point to the stroke I just added.
    strokes.back().addVertex(x, y);
}


void ofApp::mousePressed(int x, int y, int button)
{
    // Create a new stroke.
    strokes.push_back(ofPolyline());

    // Add the current point to the stroke I just added.
    strokes.back().addVertex(x, y);
}


void ofApp::loadData()
{
    ofJson json = ofLoadJson("strokes.json");

    if (!json.empty())
    {
        ofJson strokesJson = json["strokes"];

        for (const auto& strokeJson: strokesJson)
        {
            ofPolyline polyline;

            for (const auto& pointJson: strokeJson)
            {
                polyline.addVertex(pointJson["x"], pointJson["y"]);
            }

            strokes.push_back(polyline);
        }
    }
    else
    {
        ofLogError() << "Json was empty.";
    }
}


void ofApp::saveData()
{
    // ofJson is an alias for nlohmann::json
    // https://github.com/nlohmann/json
    ofJson strokesJson;

    for (const auto& polyline: strokes)
    {
        ofJson strokeJson;

        for (const auto& point: polyline)
        {
            // Two ways to do the same thing.
            ///
            // ofJson pointJson;
            // pointJson["x"] = point.x;
            // pointJson["y"] = point.y;

            ofJson pointJson = { { "x", point.x }, { "y", point.y } };

            strokeJson.push_back(pointJson);
        }

        strokesJson["strokes"].push_back(strokeJson);
    }


    // Saving pretty json will save it in a way that is easier to read.
    // ofSavePrettyJson("strokes.json", jsonStrokes);

    ofSaveJson("strokes.json", strokesJson);

}
