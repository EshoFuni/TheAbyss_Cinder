//
//  SuperCreature.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
/*
 * This is the base class for every (derived) creature class
 */
//
//

#include "SuperCreature.h"

SuperCreature::SuperCreature(){
    energy = 100.0;
//    power = 0.02;
    power = 0.0; // never die
    pos = *new Vec3f();
    projectedPos = *new Vec3f();
    rot = *new Vec3f();
    sca = *new Vec3f(1, 1, 1);
}

void SuperCreature::applyTransforms(){
        gl::translate(pos.x, pos.y, pos.z);
        gl::rotate(rot);
        gl::scale(sca);
}

