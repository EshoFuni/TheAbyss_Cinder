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
#include <stdio.h>

#include "SuperCreature.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
//#include "cinder/app/Renderer.h"
//#include "cinder/TriMesh.h"

using namespace ci;
//static const bool PREMULT = false;

class HTMPreGelly: public SuperCreature{
public:
    
    HTMPreGelly(); // constructor
    HTMPreGelly(bool dummy); // dummy variable
    // METHOD DECLARATION
    void update();
    void move();
    void draw();
    float radius; //added polygon radius
    float geomSegments; //added polygon resolution
    
    // VARIABLE DECLARATION
    Vec3f mThresh; // position threshold to change direction
    //bool dummy;
};

#endif /* defined(__TheAbyss__HTMPreGelly__) */
