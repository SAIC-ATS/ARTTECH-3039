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
    detector.setup(detectorSettings);

    ofxDlib::FaceShapePredictor::Settings shapePredictorSettings;
    shapePredictor.setup(shapePredictorSettings);

    ofxDlib::FaceCoder::Settings coderSettings;
    coder.setup(coderSettings);

    for (const auto& entry: pixelMap)
    {
        // std::string dirName = entry.first;
        // std::vector<ofPixels> images = entry.second;

        std::vector<ofTexture> alignedTextures;
        std::vector<std::vector<float>> faceCodes;

        for (auto& pixels: entry.second)
        {
            // Get the list of bounding boxes and confidences from the face detector.
            auto detections = detector.detect(pixels);

            for (auto detection: detections)
            {
                auto faceShape = shapePredictor.predict(pixels, detection.rectangle);
                ofPixels alignedFace = faceShape.alignedFace();
                ofTexture alignedTexture;
                alignedTexture.loadData(alignedFace);
                alignedTextures.push_back(alignedTexture);

                // Generate the face code.
                std::vector<float> faceCode = coder.code(alignedFace);
                faceCodes.push_back(faceCode);

                //std::string filename = "AlignedFaces/" + ofGetTimestampString() + ".jpg";
                //ofSaveImage(alignedFace, filename);
            }
        }

        faceChipsMap[entry.first] = alignedTextures;
        faceCodeMap[entry.first] = faceCodes;
    }
}


void ofApp::update()
{

}


void ofApp::draw()
{
    // Draw all faces on the screen by interating throug the face chips map.
    int x = 0;
    int y = 0;

    for (auto& texture: faceChipsMap[matchingClass])
    {
        // Draw the texture.
        texture.draw(x, y);

        // Increment the x position.
        x += texture.getWidth();

        // If we go off the right side, increment the y-position and reset
        // the x position.
        if (x + texture.getWidth() > ofGetWidth())
        {
            y += texture.getHeight();
            x = 0;
        }
    }
}


void ofApp::dragEvent(ofDragInfo dragInfo)
{
    matchingClass = "I don't know.";

    // Big assumption that someone dragged 1 image file only.
    std::string imageFilename = dragInfo.files[0];

    ofPixels pixels;
    ofLoadImage(pixels, imageFilename);

    // Get the list of bounding boxes and confidences from the face detector.
    auto detections = detector.detect(pixels);

    for (auto detection: detections)
    {
        auto faceShape = shapePredictor.predict(pixels, detection.rectangle);
        ofPixels alignedFace = faceShape.alignedFace();

        // Generate the face code.
        std::vector<float> faceCode = coder.code(alignedFace);

        // Comapre this face code to each face code in our database.
        for (auto& entry: faceCodeMap)
        {
            for (auto& knownFaceCode: entry.second)
            {
                float sum = 0;
                for (std::size_t i = 0; i < faceCode.size(); ++i)
                {
                    float diff = faceCode[i] - knownFaceCode[i];
                    float sqrDiff = diff * diff;
                    sum += sqrDiff;
                }

                // The euclidian distance between our vectors.
                float distance = std::sqrt(sum);

                if (distance < 0.5)
                {
                    matchingClass = entry.first;
                }
            }
        }
    }
}
