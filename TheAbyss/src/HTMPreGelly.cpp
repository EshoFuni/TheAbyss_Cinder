//
//  HTMPreGelly.cpp
//  TheAbyss
//
//  Created by Horácio Tomé-Marques, aka, hace, HoMy, HoArts, on 03/08/15.
//
//

#include "HTMPreGelly.h"

HTMPreGelly::HTMPreGelly(){
    creatureAuthor  = "Horácio Tomé-Marques";
    creatureName    = "PreGelly... making fun with Jellyfish pre-history";
    creatureVersion = "Zero";
    
    pos = Vec3f(0, 0, 0);
    sca = Vec3f(100, 200, 100);
    radius = 50,0;
    geomSegments = 16;

    // INPUT POSITION
    mThresh = Vec3f( Rand::randFloat(640.f)-320.f , Rand::randFloat(480.f)-240.f, Rand::randFloat(500.f)-250.f);
}

void HTMPreGelly::move(){
    if(pos.x < mThresh.x) { pos.x++; }
    else { mThresh.x = Rand::randFloat(-640.f); pos.x--; }
    
    if(pos.y < mThresh.y) { pos.y++; }
    else { mThresh.y = Rand::randFloat(-480.f); pos.y--; }
    
    if(pos.z < mThresh.z) { pos.z++; }
    else { mThresh.z = Rand::randFloat(-500.f); pos.z--; }
}

void HTMPreGelly::draw(){ // CREATURE DRAWING
    
    gl::color( ColorA( 1, 1, 0.5, 0.1f ) );
    cinder::gl::enableWireframe();
    //gl::drawCube(pos, sca);
    gl::drawSphere (pos, radius, geomSegments);
    gl::disableWireframe();
    gl::end();
}