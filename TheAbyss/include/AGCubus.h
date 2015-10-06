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
#include "Node.h"
#include "Spring.h"
#include "cinder/Rand.h"

//using namespace ci;

class AGCubus: public SuperCreature{
public:    
    AGCubus(); // constructor
    
    // METHOD DECLARATION
    virtual void move();
    virtual void draw();
    
    
    // VARIABLE DECLARATION
    Vec3f mThresh; // position threshold to change direction
};

#endif /* defined(__TheAbyss__AGCubus__) */
