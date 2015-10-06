//
//  HTMZoid.h
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 06/10/15.
//  added Tiago Ângelo on 06/10/15.
//
//

#ifndef __TheAbyss__HTMZoid__
#define __TheAbyss__HTMZoid__

#include <stdio.h>
#include "SuperCreature.h"
#include "Node.h"
#include "Spring.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"

using namespace ci;

class HTMZoid : public SuperCreature{
public:
    HTMZoid(); //Constructor
    
    // METHOD DECLARATION
    virtual void move();
    virtual void draw();
    
    // VARIABLE DECLARATION
    Vec3f fPos, fAng;
    float cSize;
    int segments;
    int numberT;
    float bLen;
    float aFreq;
    float bOffs;
    float angRange;
    float rotateVec;
    
    int frameCount;
    
};
    
#endif /* defined(__TheAbyss__HTMZoid__) */
