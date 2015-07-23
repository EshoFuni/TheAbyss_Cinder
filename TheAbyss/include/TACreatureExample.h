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

#include <iostream>

#include "cinder/Rand.h"

#include "SuperCreature.h"

using namespace ci;

class TACreatureExample: public SuperCreature{
public:
    
    TACreatureExample(); // constructor
    // METHOD DECLARATION
    void move();
    void draw();
    
    
    // VARIABLE DECLARATION
    Vec3f mThresh; // position threshold to change direction
};

#endif /* defined(__TheAbyss__TACretureExample__) */
