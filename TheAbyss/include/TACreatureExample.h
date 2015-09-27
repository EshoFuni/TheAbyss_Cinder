//
//  TACretureExample.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/22/15.
//
//  Derived class extending the SuperCreature base class
//

#ifndef __TheAbyss__TACretureExample__
#define __TheAbyss__TACretureExample__

#pragma once

#include "SuperCreature.h"
#include "cinder/Rand.h"

using namespace ci;

class TACreatureExample: public SuperCreature{
public:
    
    TACreatureExample(); // constructor
    // METHOD DECLARATION
    virtual void move();
    virtual void draw();
    
    
    // VARIABLE DECLARATION
    Vec3f mThresh; // position threshold to change direction
};

#endif /* defined(__TheAbyss__TACretureExample__) */
