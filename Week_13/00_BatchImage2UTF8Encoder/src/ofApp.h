#pragma once


#include "ofMain.h"
#include "ofxCcv.h"
#include "ofxCv.h"
#include "ofxIO.h"
#include "Poco/BinaryWriter.h"
#include "Poco/BinaryReader.h"
#include "Poco/DeflatingStream.h"


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
                SndfileHandle soundFile(path);

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

                // Find the minimum and maximum values in the sound file.
                auto result = std::minmax_element(sampleBuffer.begin(), sampleBuffer.end());
                
                ofLogNotice("ofApp::readFile") << "Min. amplitude is " << *result.first << " at sample [" << (result.first-sampleBuffer.begin()) << "].";
                ofLogNotice("ofApp::readFile") << "Max. amplitude is " << *result.second << " at sample [" << (result.second-sampleBuffer.begin()) << "].";



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


class ImageToUTF8Encoder
{
public:
    ImageToUTF8Encoder(const ofJson& settings)
    {
        ofJson pixelFormat = settings["pixel_format"];
        _width = pixelFormat["width"];
        _height = pixelFormat["height"];
        _numChannels = pixelFormat["num_channels"];

        ofJson encoding = settings["encoding"];

        _unicodeOffset = encoding["unicode_offset"];
        _startCode = encoding["start_code"];
        _rowEndCode = encoding["row_end_code"];

    }

    ~ImageToUTF8Encoder()
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
        _thread = std::thread(&ImageToUTF8Encoder::run, this);
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

                ofImage img;
                img.setUseTexture(false);
                img.load(path.string());
                img.setImageType(OF_IMAGE_GRAYSCALE);

                if (img.getWidth() > img.getHeight())
                {
                    int offsetX = (img.getWidth() - img.getHeight()) / 2;
                    img.crop(offsetX, 0, img.getHeight(), img.getHeight());
                }
                else if (img.getWidth() < img.getHeight())
                {
                    int offsetY = (img.getHeight() - img.getWidth()) / 2;
                    img.crop(0, offsetY, img.getWidth(), img.getWidth());
                }

                img.resize(_width, _height);

                std::filesystem::path p = pathAndBase;
                p += ".g.jpg";

                ofSaveImage(img.getPixels(), p);

                ofPixels pixels;
                ofxCv::imitate(img.getPixels(), pixels);

                cv::Mat src = ofxCv::toCv(img.getPixels());
                cv::Mat dst;

                cv::equalizeHist(src, dst);

                 ofxCv::copy(dst, pixels);

                std::filesystem::path pe = pathAndBase;
                pe += ".ge.jpg";

                ofSaveImage(pixels, pe);

                std::string buffer;

                for (std::size_t y = 0; y < img.getHeight(); ++y)
                {
                    for (std::size_t x = 0; x < img.getWidth(); ++x)
                    {
                        if (x == 0 && y == 0)
                        {
                            ofUTF8Append(buffer, _startCode);
                        }
                        else if (x == img.getWidth() - 1)
                        {
                            ofUTF8Append(buffer, _rowEndCode);
                        }
                        else
                        {
                            ofUTF8Append(buffer, img.getColor(x, y).getBrightness() + _unicodeOffset);
                        }
                    }
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

    int _width = 0;
    int _height = 0;
    int _numChannels = 0;

    std::uint32_t _unicodeOffset = 0;
    std::uint32_t _startCode = 0;
//    std::uint32_t _endCode = 0;
//    std::uint32_t _rowStartCode = 0;
    std::uint32_t _rowEndCode = 0;

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
    
    std::vector<std::unique_ptr<ImageToUTF8Encoder>> imageEncoders;
    std::vector<std::unique_ptr<AudioToUTF8Encoder>> audioEncoders;

    std::size_t currentWorkerIndex = 0;

    std::unique_ptr<ofxIO::RegexPathFilter> fileFilter;

};
