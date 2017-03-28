#include "ofApp.h"
#include "Poco/BinaryWriter.h"
#include "Poco/BinaryReader.h"
#include "Poco/InflatingStream.h"


void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);

    ofJson settings = ofLoadJson("settings.json");

    std::string imagesPath = settings["images"];

    std::string network = settings["network"];
    int layer = settings["layer"];

    ofLogNotice() << "Loading extracted features from " << imagesPath << " with network: " << network << " layer: " << layer;

    std::string dataSuffix = "." + network + "." + std::to_string(layer) + ".dat";

    ofLogNotice() << "Data suffix: " << dataSuffix;

    ofxIO::RegexPathFilter filter(".*" + dataSuffix);
    
    ofLogNotice() << "Finding data files ... ";

    std::vector<std::filesystem::path> files;
    ofxIO::DirectoryUtils::listRecursive(imagesPath, files, true, &filter);

    ofLogNotice() << "Found " << files.size();

//    std::string fileListPath = ofToDataPath("file_list.json", true);
//    ofLogNotice() << "Saving file list to " << fileListPath;
//    std::vector<std::filesystem::path> fileList;
//    for (auto& file: files) fileList.push_back(file.string());
//    ofSavePrettyJson(fileListPath, fileList);


    ofLogNotice() << "Calculating embeddings w/ t-sne ... ";

    std::vector<std::vector<float>> encodings;
    
    std::size_t lastSize = 0;

    ofLogNotice() << "Reading encodings from batch encoder ...";

    std::vector<std::filesystem::path> imageFiles;
    std::vector<std::filesystem::path> dataFiles;

    for (std::size_t i = 0; i < files.size(); ++i)
    {
        std::ifstream istr(files[i].string(), std::ios::binary);
        Poco::InflatingInputStream inflating(istr, Poco::InflatingStreamBuf::STREAM_GZIP);
        Poco::BinaryReader reader(inflating);
        reader.readBOM();
        std::size_t size;
        std::vector<float> encoding;
        
        reader >> size;

        ofLogNotice() << "Adding encoding for ... " << i << " / " << files.size() << std::endl;
        
        if (i == 0)
        {
            lastSize = size;
        }
        else if (size != lastSize)
        {
            ofLogError() << "There was an error reading " << files[i] << " so skipping.";
            continue;
        }
        
        size = lastSize;

        ofLogNotice() << "De-serializing encodings for " << files[i];

        for (std::size_t i = 0; i < size; ++i)
        {
            float f;
            reader >> f;
            encoding.push_back(f);
        }
        
        encodings.push_back(encoding);

        dataFiles.push_back(files[i].string());

        std::string imageFilename = files[i].string();

        ofStringReplace(imageFilename, dataSuffix, "");

        imageFiles.push_back(imageFilename);

    }

    ofLogNotice() << "Beginning t-sne ...";

    ofxTSNE tsne;
    std::vector<std::vector<double>> imagePoints;

    // Run t-SNE and load image points to imagePoints
    ofLogNotice("ofApp::setup") << "Run t-SNE on images with settings: ";


    ofLogNotice("ofApp::setup") << settings["tsne"].dump(4);

    imagePoints = tsne.run(encodings,
                           settings["tsne"]["dims"],
                           settings["tsne"]["perplexity"],
                           settings["tsne"]["theta"],
                           settings["tsne"]["normalize"]);


    ofLogNotice("ofApp::setup") << "Image points found: " << imagePoints.size();

    std::string embeddingsFilename = ofToDataPath("image_embeddings.json", true);

    ofLogNotice("ofApp::setup") << "Saving embeddings to: " << embeddingsFilename;

    // fill JSON with imagePoints coordinates of each image
    ofJson output;

    for (auto i=0; i < imageFiles.size(); i++)
    {
        ofJson json = {
            { "image_file", imageFiles[i].string() },
            { "data_file", dataFiles[i].string() },
            { "x", imagePoints[i][0] },
            { "y", imagePoints[i][1] }//,
            //{ "z", imagePoints[i][2] } // if we use a third or more dimensions
        };
        
        output.push_back(json);
    }

    ofSavePrettyJson(embeddingsFilename, output);

    ofLogNotice() << "Now go assign those points to a grid if you want ...";

    ofExit();
}


