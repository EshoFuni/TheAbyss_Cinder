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
<<<<<<< HEAD
#include <stdio.h>

#include "SuperCreature.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
//#include "cinder/app/Renderer.h"
//#include "cinder/TriMesh.h"

using namespace ci;
//static const bool PREMULT = false;
=======

#include "SuperCreature.h"

using namespace ci;
>>>>>>> Tiago_dev

class HTMPreGelly: public SuperCreature{
public:
    
    HTMPreGelly(); // constructor
<<<<<<< HEAD
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
=======
    // METHOD DECLARATION
    void update();
    virtual void move();
    virtual void draw();
    
    // VARIABLE DECLARATION
    Vec3f mThresh; // position threshold to change direction
    float radius; //added polygon radius
    float geomSegments; //added polygon resolution
    
>>>>>>> Tiago_dev
};

#endif /* defined(__TheAbyss__HTMPreGelly__) */
