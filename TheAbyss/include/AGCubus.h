//
//  AGCubus.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
//
//

#ifndef __TheAbyss__AGCubus__
#define __TheAbyss__AGCubus__


#pragma once

#include "SuperCreature.h"
#include "cinder/Rand.h"

//using namespace ci;

class AGCubus: public SuperCreature{
public:
    
    AGCubus(); // constructor
    AGCubus(bool dummy); // dummy variable
    // METHOD DECLARATION
    void move();
    void draw();
    
    
    // VARIABLE DECLARATION
    Vec3f mThresh; // position threshold to change direction
    //bool dummy;
};

#endif /* defined(__TheAbyss__AGCubus__) */
