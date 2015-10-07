//
//  TAHubert.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 10/7/15.
//
//

#ifndef __TheAbyss__TAHubert__
#define __TheAbyss__TAHubert__

#pragma once
#include "SuperCreature.h"

using namespace ci;

class TAHubert: public SuperCreature{
public:
    TAHubert(); // constructor
    //METHOD DECLARATION
    virtual void move();
    virtual void draw();
    
    //VARIABLE DECLARATION
    int nLegs; // how many legs
    float lLength; // lenght length
    int nCubes; // how many cubes per leg
    Vec3f cubeSize; // cube size
    Vec3f freqMulPos, freqMulAng;
    
    float size; // creature scale
private:
    int count;
    int initCubeSize; 
    float ang;
//    int angCount;
    Vec3f drawingRotation;
};

#endif /* defined(__TheAbyss__TAHubert__) */
