//
//  OTFather.h
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 04/10/15.
//  added Tiago Ângelo on 06/10/15.
//

#ifndef __TheAbyss__AGWorm__
#define __TheAbyss__AGWorm__

#pragma once

#include "SuperCreature.h"
#include "Node.h"
#include "Spring.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
//#include <math.h>

using namespace ci;

class OTFather : public SuperCreature{
public:
    OTFather(); //Constructor
    
    // METHOD DECLARATION
    virtual void move();
    virtual void draw();
    
    // VARIABLE DECLARATION
    int count;
    int numSegmenti;
    int numTentacoli;
    int numPinne;
    float distPinne;
    float l;
    int detail = 2;
    Perlin mPerlin;
    
    float sm1, sm2;
    float rx, ry;
    Vec3f pVel, rVel, noiseVel;
    //Vec3d pVel, rVel, noiseVel;
    
    int frameCount;
    
};

#endif /* defined(__TheAbyss__OTFather__) */