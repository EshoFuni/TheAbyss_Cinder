//
//  SuperCreature.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
//
//

#ifndef __TheAbyss__SuperCreature__
#define __TheAbyss__SuperCreature__

#pragma once
#include "cinder/Rand.h"

using namespace ci;
using namespace std;

class SuperCreature {
public:
    
    
    SuperCreature(); // constructor
    virtual ~SuperCreature(){}; // virtual destructor
    
    virtual void move(){};
    virtual void draw(){};
    virtual void complexPlus(){};
    virtual void complexMinus(){};
    void applyTransforms();
    
    string creatureName, creatureAuthor, creatureVersion;
    //CreatureDate creatureDate;
    
    
protected:
    Vec3f pos, rot, sca;
private:
    Vec3f projectedPos;
    float energy, power;

//    CreatureManager cm;

};

#endif /* defined(__TheAbyss__SuperCreature__) */
