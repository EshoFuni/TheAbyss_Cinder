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
#include "OscListener.h"


using namespace std;
//using namespace cinder::app;

class BCIWave {
public:
    BCIWave(); //using default constructor because of (cinder::app)
    BCIWave(int port, bool verb); // constructor
    void draw();
    void update();
    
    float amp; // signal amplitude value
    float maxAmp; // signal maximum amplitude
    float offset; // signal offset (X axis)
    float speed; // signal speed on Y axis
    float trail; // signal trail amount
    bool verbose; // print osc message to console
    
private:
    cinder::osc::Listener listener;

};

#endif /* defined(__TheAbyss__BCIWave__) */
