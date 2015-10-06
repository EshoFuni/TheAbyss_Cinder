//
//  PXPSonar.h
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 04/10/15.
//  added Tiago Ângelo on 06/10/15.
//

#ifndef __TheAbyss__PXPSonar__

#pragma once

#include "SuperCreature.h"
#include "cinder/Rand.h"
#include "cinder/Sphere.h"
//#include <math.h>
#define __TheAbyss__PXPSonar__

using namespace ci;

class PXPSonar : public SuperCreature{
public:
    PXPSonar(); //Constructor
    
    // METHOD DECLARATION
    virtual void move();
    virtual void draw();
    
    // VARIABLE DECLARATION
    int time;
    int count;
    int bold = 2;
//    int freq = 300; // Processing
    int freq = 300; // Processing
    float fadeSpeed = 5.f;
    Vec3f freqMulRot, freqMulSca, freqMulPos;
    Sphere s1, s2;
    
private:
    int frameCount;
    //    app::getElapsedFrames()
};

#endif /* defined(__TheAbyss__PXPSonar__) */
