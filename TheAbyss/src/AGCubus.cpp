//
//  AGCubus.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
//
// For testing purposes this class is similar to TACreatureExample, but should then by replaced by the real AGCUbus
//
//

#include "AGCubus.h"

AGCubus::AGCubus(){
    creatureAuthor  = "Tiago Ângelo";
    creatureName    = "AGCubus";
    creatureVersion = "Zero";
    
    
    pos = Vec3f(0, 0, 0);
    sca = Vec3f(100, 100, 100);
    
    mThresh = Vec3f( Rand::randFloat(640.f)-320.f , Rand::randFloat(480.f)-240.f, Rand::randFloat(500.f)-250.f);
}


void AGCubus::move(){
    if(pos.x < mThresh.x) { pos.x++; }
    else { mThresh.x = Rand::randFloat(-640.f); pos.x--; }
    
    if(pos.y < mThresh.y) { pos.y++; }
    else { mThresh.y = Rand::randFloat(-480.f); pos.y--; }
    
    if(pos.z < mThresh.z) { pos.z++; }
    else { mThresh.z = Rand::randFloat(-500.f); pos.z--; }
    
}

void AGCubus::draw(){
    gl::drawStrokedCube(pos, sca);
}

void AGCubus::complexPlus(){
    // complexify creature
}

void AGCubus::complexMinus(){
    // de-complexify creature
}