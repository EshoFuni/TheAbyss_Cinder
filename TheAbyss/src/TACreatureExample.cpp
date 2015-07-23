//
//  TACretureExample.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/22/15.
//
// Basic example of a creature class.
// Start from this example to create more complex creatures
//
//

#include "TACreatureExample.h"

TACreatureExample::TACreatureExample(){
    creatureAuthor  = "Tiago Ângelo";
    creatureName    = "Example";
    creatureVersion = "Zero";
    
    
    pos = Vec3f(0, 0, 0);
    sca = Vec3f(100, 100, 100);
    
    mThresh = Vec3f( Rand::randFloat(640.f)-320.f , Rand::randFloat(480.f)-240.f, Rand::randFloat(500.f)-250.f);
    
}


void TACreatureExample::move(){
    if(pos.x < mThresh.x) { pos.x++; }
    else { mThresh.x = Rand::randFloat(-640.f); pos.x--; }
    
    if(pos.y < mThresh.y) { pos.y++; }
    else { mThresh.y = Rand::randFloat(-480.f); pos.y--; }
    
    if(pos.z < mThresh.z) { pos.z++; }
    else { mThresh.z = Rand::randFloat(-500.f); pos.z--; }
    
}

void TACreatureExample::draw(){
    //gl::drawCube(mPos, mSize);
    //gl::drawColorCube(mPos, mSize);
    gl::drawStrokedCube(pos, sca);
}