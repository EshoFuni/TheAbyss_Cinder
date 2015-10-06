//
//  AGWorm.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 10/3/15.
//
//

#ifndef __TheAbyss__AGWorm__
#define __TheAbyss__AGWorm__

#pragma once

#include "SuperCreature.h"
#include "Node.h"
#include "Spring.h"
#include "cinder/Rand.h" 

using namespace ci;

class AGWorm : public SuperCreature{
public:
    AGWorm(); //Constructor

    // METHOD DECLARATION
    virtual void move();
    virtual void draw();
    virtual void complexPlus();
    virtual void complexMinus();
    
    // VARIABLE DECLARATION
    std::vector<Node> nodes;
    std::vector<Spring> springs;
    Vec3f dest;
    float nervosismo;
    float radius;
    float rSpeed, rDamp;
    float freq1, freq2;
    
    int frameCount;
    
private:
    int num;
    float len;
    float damp;
    float k;
    
};

#endif /* defined(__TheAbyss__AGWorm__) */
