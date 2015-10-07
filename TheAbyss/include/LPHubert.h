//
//  LPHubert.h
//  TheAbyss
//
//  Adapted by Tiago Ângelo and Horácio Tomé-Marques on 10/7/15.
//
//

#ifndef __TheAbyss__LPHubert__
#define __TheAbyss__LPHubert__

#pragma once

#include "SuperCreature.h"

using namespace ci;

class LPHubert : public SuperCreature{
public:
    LPHubert(); // constructor
    //METHOD DECLARATION
    virtual void move();
    virtual void draw();
    Vec2f rotateVec(Vec2f v, float angle);
    
    Vec3f freqMulPos, freqMulAng;
    int num;
    int count;
    
    float cSize;
    float bLen;
    float aFreq;
    float bOffs;
    float angRange;
    float angT, scaR;
    
    int numberT, numberSeg, elSize, val2div;
    
//    bool isAngry = false;
};

#endif /* defined(__TheAbyss__LPHubert__) */
