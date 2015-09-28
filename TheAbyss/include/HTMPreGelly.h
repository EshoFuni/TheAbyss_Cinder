//
//  HTMPreGelly.h
//  TheAbyss
//
//  Created by Horácio Tomé-Marques, aka, hace, HoMy, HoArts, on 03/08/15.
//
//

#ifndef __TheAbyss__HTMPreGelly__
#define __TheAbyss__HTMPreGelly__

#pragma once

#include "SuperCreature.h"

using namespace ci;

class HTMPreGelly: public SuperCreature{
public:
    
    HTMPreGelly(); // constructor
    // METHOD DECLARATION
    void update();
    virtual void move();
    virtual void draw();
    
    // VARIABLE DECLARATION
    Vec3f mThresh; // position threshold to change direction
    float radius; //added polygon radius
    float geomSegments; //added polygon resolution
    
};

#endif /* defined(__TheAbyss__HTMPreGelly__) */
