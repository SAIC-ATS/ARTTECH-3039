#pragma once


#include "ofMain.h"
#include "ofxLibsndfile.h"
#include "ofxIO.h"


class AudioToUTF8Encoder
{
public:
    AudioToUTF8Encoder(const ofJson& settings)
    {
        ofJson pixelFormat = settings["audio_format"];
        _sampleRate = pixelFormat["sample_rate"];
        _bitsPerSample = pixelFormat["bits_per_sample"];
        _numChannels = pixelFormat["num_channels"];

        ofJson encoding = settings["encoding"];

        _unicodeOffset = encoding["unicode_offset"];

    }

    ~AudioToUTF8Encoder()
    {
        stop();

        if (_thread.joinable())
        {
            try
            {
                _thread.join();
            }
            catch (const std::exception& exc)
            {
                std::cout << exc.what() << std::endl;
            }
        }
    }

    void start()
    {
        _thread = std::thread(&AudioToUTF8Encoder::run, this);
    }

    void stop()
    {
        _isRunning = false;
        _channel.close();
    }

    bool encode(const std::filesystem::path& file)
    {
        return _channel.send(file);
    }

    std::size_t size() const
    {
        return _channel.size();
    }

private:
    void run()
    {
        _isRunning = true;

        while (_isRunning)
        {
            std::filesystem::path path;

            if (_channel.receive(path))
            {
                std::filesystem::path pathAndBase = path.parent_path() / std::filesystem::basename(path);

                std::string buffer;

                // Load the file into a handle.
                SndfileHandle soundFile(path.string());

                // Query parameters.
                ofLogNotice("ofApp::readFile") << "Opened file " << path;
                ofLogNotice("ofApp::readFile") << "\t     Format:" << soundFile.format();
                ofLogNotice("ofApp::readFile") << "\tSample Rate:" << soundFile.samplerate();
                ofLogNotice("ofApp::readFile") << "\t   # Frames:" << soundFile.frames();
                ofLogNotice("ofApp::readFile") << "\t # Channels:" << soundFile.channels();

                // Calculate duration.
                std::size_t numSamples = soundFile.channels() * soundFile.frames();
                uint64_t durationMicros = (1000000 * soundFile.frames()) / soundFile.samplerate();
                float durationMillis = durationMicros / 1000.0f;

                ofLogNotice("ofApp::readFile") << "\t  # Samples:" << numSamples;
                ofLogNotice("ofApp::readFile") << "\tDuration MS:" << durationMillis;
                ofLogNotice("ofApp::readFile") << "\tDuration uS:" << durationMicros;

                // Create a buffer with the right number of samples.
                std::vector<float> sampleBuffer(numSamples, 0.0f);

                // Read the samples into the memory buffer.
                // libsndfile will automatically normalize data when reading into float
                // buffers. See this link http://www.mega-nerd.com/libsndfile/api.html#note1
                auto numRead = soundFile.read(sampleBuffer.data(), sampleBuffer.size());

                ofLogNotice("ofApp::readFile") << "Loaded file with " << numRead << " samples.";

//                // Find the minimum and maximum values in the sound file.
//                auto result = std::minmax_element(sampleBuffer.begin(), sampleBuffer.end());
//                
//                ofLogNotice("ofApp::readFile") << "Min. amplitude is " << *result.first << " at sample [" << (result.first-sampleBuffer.begin()) << "].";
//                ofLogNotice("ofApp::readFile") << "Max. amplitude is " << *result.second << " at sample [" << (result.second-sampleBuffer.begin()) << "].";

                for (float& f: sampleBuffer)
                {
                    uint32_t s = uint32_t(ofMap(float(f + 1), 0, 2, _unicodeOffset, _unicodeOffset + 255, true));
                    ofUTF8Append(buffer, s);
                }

                std::filesystem::path textPath = pathAndBase;
                textPath += ".txt";

                ofBuffer b;
                b.set(buffer);

                ofBufferToFile(textPath, b);
            }
        }

        _channel.close();
    }

    int _sampleRate = 0;
    int _numChannels = 0;
    int _bitsPerSample = 0;

    std::uint32_t _unicodeOffset = 0;

    /// \brief The internal thread.
    std::thread _thread;
    
    /// \brief True if the thread is running.
    std::atomic<bool> _isRunning;
    
    /// \brief The queue of files to encode.
    ofxIO::ThreadChannel<std::filesystem::path> _channel;
    
};


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void process(const std::filesystem::path& path);

    void dragEvent(ofDragInfo dragInfo) override;
    
    void encode(const std::filesystem::path& path);
    
    std::vector<std::unique_ptr<AudioToUTF8Encoder>> encoders;

    std::size_t currentWorkerIndex = 0;

    std::unique_ptr<ofxIO::RegexPathFilter> fileFilter;

};
