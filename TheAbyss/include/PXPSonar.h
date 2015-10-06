//
//  PXPSonar.h
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 04/10/15.
//  added Tiago Ângelo on 06/10/15.
//

#ifndef __TheAbyss__PXPSonar__
#define __TheAbyss__PXPSonar__

#pragma once

//#include <stdio.h>
#include "SuperCreature.h"
#include "Node.h"
#include "Spring.h"
#include "cinder/Rand.h"
#include "cinder/Sphere.h"
//#include <math.h>

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
    float freq = 300.f;
    float fadeSpeed = 1.f;
    Vec3f freqMulRot, freqMulSca, freqMulPos;
    
    int frameCount;
    
};

#endif /* defined(__TheAbyss__PXPSonar__) */
