#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);

    ofDirectory faceDataDir("FaceDataSet/");

    // Iterate through all directories in our face data set.
    for (auto subDir: faceDataDir)
    {
        // Make sure we only look at directories and ignore the files.
        if (subDir.isDirectory())
        {
            std::string dirName = subDir.getFileName();

            // Only show image files with the given file extensions.
            ofDirectory faceDataDir(subDir.getAbsolutePath());
            faceDataDir.allowExt("jpg");
            faceDataDir.allowExt("jpeg");
            faceDataDir.allowExt("jp2");
            faceDataDir.allowExt("png");

            std::cout << subDir.getAbsolutePath() << std::endl;

            std::vector<ofPixels> images;

            // Iterate through all of the images in the current face data directory.
            for (auto imageFile: faceDataDir)
            {
                ofPixels pixels;
                ofLoadImage(pixels, imageFile.getAbsolutePath());
                images.push_back(pixels);
            }

            pixelMap[dirName] = images;
        }
    }

    ofxDlib::FaceDetector::Settings detectorSettings;
    ofxDlib::FaceDetector detector;
    detector.setup(detectorSettings);

    ofxDlib::FaceShapePredictor::Settings shapePredictorSettings;
    ofxDlib::FaceShapePredictor shapePredictor;
    shapePredictor.setup(shapePredictorSettings);

    for (const auto& entry: pixelMap)
    {
        // std::string dirName = entry.first;
        // std::vector<ofPixels> images = entry.second;

        for (auto& pixels: entry.second)
        {
            // Get the list of bounding boxes and confidences from the face detector.
            auto detections = detector.detect(pixels);

            for (auto detection: detections)
            {
                auto faceShape = shapePredictor.predict(pixels, detection.rectangle);

                ofPixels alignedFace = faceShape.alignedFace();

                std::string filename = "AlignedFaces/" + ofGetTimestampString() + ".jpg";
                ofSaveImage(alignedFace, filename);
            }
        }
    }
}


void ofApp::update()
{

}


void ofApp::draw()
{

}
