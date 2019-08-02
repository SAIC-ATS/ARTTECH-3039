#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    grabber.setup(960, 720);
    
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ofxCv::ObjectFinder::Fast);
    
    ofLoadImage(eyeMask, "eye_mask.png");
}


void ofApp::update()
{
    auto iter = particles.begin();
    while (iter != particles.end())
    {
        if (iter->age > 60)
            iter = particles.erase(iter);
        else
            ++iter;
    }
    
    
    for (auto& p: particles)
    {
        p.update();
    }
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        finder.update(grabber.getPixels());
    }

    
    for (std::size_t i = 0; i < finder.size(); i++)
    {
        ofRectangle smoothedRect = finder.getObjectSmoothed(i);
        ofRectangle rect = finder.getObject(i);
        std::size_t label = finder.getLabel(i);
        std::size_t age = finder.getTracker().getAge(label);
        
        float eyeY = smoothedRect.getTop() + smoothedRect.getHeight() * 0.40;
        
        float faceWidth = smoothedRect.getWidth();
        float faceCenterX = smoothedRect.getCenter().x;
        
        float eyeRightX = faceCenterX + faceWidth * .2;
        float eyeLeftX = faceCenterX - faceWidth * .2;
        
        float eyeWidth = faceWidth / 5.;
        float eyeHeight = eyeWidth / 2.;

        glm::vec2 eyeRight = { eyeRightX, eyeY };
        glm::vec2 eyeLeft = { eyeLeftX, eyeY };

        ofPixels leftEyePixels = grabber.getPixels();
        ofPixels rightEyePixels = grabber.getPixels();

        rightEyePixels.crop(eyeRight.x - eyeWidth / 2, eyeRight.y - eyeHeight / 2, eyeWidth, eyeHeight);
        leftEyePixels.crop(eyeLeft.x - eyeWidth / 2, eyeLeft.y - eyeHeight / 2, eyeWidth, eyeHeight);

        ofPixels eyeMaskPixels = eyeMask;
        eyeMaskPixels.resize(eyeWidth, eyeHeight);
        
        ofTexture eyeMaskTexture;
        eyeMaskTexture.loadData(eyeMaskPixels);
        
        rightEyeTexture = ofTexture();
        rightEyeTexture.loadData(rightEyePixels);
        rightEyeTexture.setAlphaMask(eyeMaskTexture);
        rightEyeTexture.setAnchorPercent(0.5, 0.5);
        leftEyeTexture = ofTexture();
        leftEyeTexture.loadData(leftEyePixels);
        leftEyeTexture.setAlphaMask(eyeMaskTexture);
        leftEyeTexture.setAnchorPercent(0.5, 0.5);

        Particle leftEyeParticle;
        leftEyeParticle.position = eyeLeft;
        leftEyeParticle.velocity = { ofRandom(-5, 5), ofRandom(-5, 5) };
        leftEyeParticle.color = ofColor::white;//ofColor::fromHsb(ofRandom(255), 255, 255);
        leftEyeParticle.texture = leftEyeTexture;
        particles.push_back(leftEyeParticle);

        Particle rightEyeParticle;
        rightEyeParticle.position = eyeRight;
        rightEyeParticle.velocity = { ofRandom(-5, 5), ofRandom(-5, 5) };
        rightEyeParticle.color = ofColor::white;//ofColor::fromHsb(ofRandom(255), 255, 255);
        rightEyeParticle.texture = rightEyeTexture;
        particles.push_back(rightEyeParticle);
    }
}


void ofApp::draw()
{
    ofSetColor(ofColor::white);
    grabber.draw(0, 0);

    for (auto& p: particles)
    {
        p.draw();
    }
}

