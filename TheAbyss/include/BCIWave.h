//
//  BCIWave.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 9/28/15.
//
//

#ifndef __TheAbyss__BCIWave__
#define __TheAbyss__BCIWave__

#pragma once
#include <iostream> // really needed ?
#include <vector> // needed ?
#include "OscListener.h"

#include "cinder/Color.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"

using namespace std;
//using namespace cinder::app;
using namespace ci;

class BCIWave {
public:
    BCIWave(); //using default constructor because of (cinder::app)
    BCIWave(int port, string address, int offset, float maxAmp, float speed, bool verbose); // constructor
    void update();
    void draw();
    void wave();
    
    string mAddress;
    float mAmp; // signal amplitude value
    float mMaxAmp; // signal maximum amplitude
    int mOffset; // signal offset (X axis)
    float mSpeed; // signal speed on Y axis
    float mTrail; // signal trail amount
    bool mVerbose; // print osc message to console
    ColorA mColor; // wave trace color
    Path2d mWave; // wave line
    
private:
    osc::Listener listener;
    int width, height; // screen width and height
    float yPos; // current y position
    float pYPos; // previous y position
    float pAmp; // previous amp value
};

#endif /* defined(__TheAbyss__BCIWave__) */
