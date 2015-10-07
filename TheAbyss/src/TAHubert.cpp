//
//  TAHubert.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 10/7/15.
//
//

#include "TAHubert.h"

TAHubert::TAHubert(){
    nLegs = 4;
    lLength = 60;
    nCubes = 3;
    cubeSize = *new Vec3f(1, 1, 1);
    cubeSize *= 20.f;
    initCubeSize = 20;
    
    size = 0.5f;
    sca = *new Vec3f(1, 1, 1);
    sca *= size;
    
    drawingRotation = *new Vec3f(Vec3f::zero());
    
    //Mouvement alétoire
    freqMulPos = *new Vec3f(1, 1, 1);
    freqMulPos *= randFloat(-0.02, 0.02);
    ang = randFloat(-0.02, 0.02);
    
    freqMulAng = *new Vec3f(1, 1, 1);
    freqMulAng *= randFloat(-0.05, 0.05);
    pos = *new Vec3f(Vec3f::zero());
    rot = *new Vec3f(Vec3f::zero());

}

void TAHubert::move(){
    count++;
    pos.x += sin(count*freqMulPos.x);
    pos.y += sin(count*freqMulPos.y);
    pos.z += sin(count*freqMulPos.z);
    rot.x += sin(count*freqMulAng.x) * M_2_PI;
    rot.y += sin(count*freqMulAng.y) * M_2_PI;
    rot.z += sin(count*freqMulAng.z) * M_2_PI;
    
    cubeSize += sin(count*0.01) * 0.05f;
    app::console() << "cube size: " << cubeSize << endl;
    
    drawingRotation.y = sin(count*freqMulAng.y) * 90.f;

//    app::console() << "pos: " << pos << endl;
//    app::console() << "rot: " << rot << endl;
//    app::console() << "sca: " << sca << endl;
}

void TAHubert::draw(){
    applyTransforms();

    gl::pushMatrices();
    
    // DRAW LEG by LEG (with cubes)
    for (int i=0; i < nLegs; i++) {
        gl::rotate(Vec3f(0, 0, 360.f/nLegs * i)); // rotation to draw equally spaced legs
        gl::pushMatrices();
        
        for (int j = 0; j < nCubes ; j++){
            drawingRotation.y = sin(count*ang) * 45.f;
            if(j > 0)gl::rotate(drawingRotation);
            gl::drawLine(Vec3f::zero(), Vec3f(lLength, 0, 0));
            gl::translate(lLength, 0);
            gl::drawStrokedCube(Vec3f::zero(), cubeSize);
        }
        gl::rotate(drawingRotation);
        gl::drawLine(Vec3f::zero(), Vec3f(lLength*1.5, 0, 0));
        gl::popMatrices();
    }
    gl::popMatrices();
}
