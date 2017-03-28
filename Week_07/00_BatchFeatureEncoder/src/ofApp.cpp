#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(1);
    
    ofSetLogLevel(OF_LOG_VERBOSE);

    ofJson settings;
    ofFile file("settings.json");
    if (file.exists()) file >> settings;
    
    ofJson _extensions = settings["file_extensions"];
    
    fileFilter = std::make_unique<ofxIO::RegexPathFilter>(settings.value("filename_filter", ".*jpg"));
    
    ofJson _layersToEncode = settings["layers_to_encode"];
    
    std::vector<size_t> layersToEncode;
    
    if (!_layersToEncode.empty())
        for (auto& layer: _layersToEncode)
            layersToEncode.push_back(layer);
    else layersToEncode.push_back(6);

    bool encodeIntermediaLayers = settings.value("encode_intermediate_layers", true);
    
    std::string network = settings.value("network", "image-net-2012.sqlite3");
    bool forceEncode = settings.value("force_encode", false);
    std::size_t numWorkers = settings.value("num_workers", 7);

    for (std::size_t i = 0; i < numWorkers; ++i)
    {
        auto encoder = std::make_unique<CCVEncoder>(network, layersToEncode);
        encoder->start();
        encoders.push_back(std::move(encoder));
    }

    // It will start with these images.
    std::string images = settings["initial_directory_to_process"];
    process(images);

    ofSetBackgroundColor(0);
}


void ofApp::update()
{
    /*
    for (std::size_t i = 0; i < encoders.size(); ++i)
    {
        std::stringstream ss;
        ss << "Worker " << i << " - Jobs Queued: " << encoders[i]->size();
        std::cout << ss.str() << std::endl;
    }

    std::cout << "---" << std::endl;
    */
}


void ofApp::draw()
{
    int x = 15;
    int y = 15;
    
    ofDrawBitmapString("Drop image files / folders\nto encode.", x, y);
    
    x += 5;
    y += 35;
    
    for (std::size_t i = 0; i < encoders.size(); ++i)
    {
        std::stringstream ss;
        ss << "Worker " << i << " - Jobs Queued: " << encoders[i]->size();
        ofDrawBitmapString(ss.str(), x, y);
        y+= 15;
    }
}


void ofApp::process(const std::filesystem::path& _path)
{
    std::filesystem::path path = ofToDataPath(_path, true);

    if (std::filesystem::is_directory(path))
    {
        std::vector<std::filesystem::path> files;

        ofxIO::DirectoryUtils::list(path, files, true, fileFilter.get());

        // Submit encode.
        for (auto& f: files) encode(f);
    }
    else if (std::filesystem::is_regular_file(path))
    {
        if (fileFilter->accept(Poco::Path(path.string())))
        {
            encode(path);
        }
    }
    else
    {
        ofLogError("ofApp::dragEvent") << "Skipping irregular file: " << path.string();
    }
}


void ofApp::dragEvent(ofDragInfo dragInfo)
{
    ofLogNotice("ofApp::dragEvent") << "Got dropped files.";

    for (auto& file: dragInfo.files)
    {
        process(file);
    }
}


void ofApp::encode(const std::filesystem::path& path)
{
    currentWorkerIndex = (currentWorkerIndex + 1) % encoders.size();

    if (!encoders[currentWorkerIndex]->encode(path))
    {
        ofLogError("ofApp::encode") << "Unable to submit image to encoder " << currentWorkerIndex << " : " << path;
    }
}
