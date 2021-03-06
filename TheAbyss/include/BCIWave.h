//
//  BCIWave.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 9/28/15.
//  ALSO SEE:
//  http://www.creativeapplications.net/tutorials/guide-to-meshes-in-cinder-cinder-tutorials/
//  http://www.songho.ca/opengl/gl_vertexarray.html
//  http://www.songho.ca/opengl/gl_vbo.html
//
//

#ifndef __TheAbyss__BCIWave__
#define __TheAbyss__BCIWave__

#pragma once
#include "OscListener.h"
#include "cinder/Rand.h"



using namespace std;
//using namespace cinder::app;
using namespace ci;

class BCIWave {
public:
    BCIWave(); //using default constructor because of (cinder::app)
    BCIWave(int port, string address, string eAddress, int offset, float maxAmp, float speed, int size, bool verbose); // constructor
    void update(); // read osc messages and update values (mAmp, yPos, eventTrigger)
    void draw(); // draw wave
    void wave(); // set wave path
    void event();
    
    string waveAddress;
    string eventAddress;
    vector<float> mAmp; // signal amplitude value (vector)
    
    float mMaxAmp; // signal maximum amplitude
    int mOffset; // signal offset (X axis)
    float mSpeed; // signal speed on Y axis
    int mSize; // wave size (vector size)
    bool mVerbose; // print osc message to console
    vector<float> mColor; // wave trace color
//    Path2d mWave; // wave line
    
private:
    osc::Listener listener;
    int width, height; // screen width and height
    float mTrail; // signal trail amount
    vector<float> yPos; // current y position
    float pYPos; // previous y position
    float pAmp; // previous amp value
    int eventTrigger; // variable used to trigger events
    int eventXStart, eventYStart, eventX, eventY;
    float eventColor;
    float eventSpeed;
};

#endif /* defined(__TheAbyss__BCIWave__) */
