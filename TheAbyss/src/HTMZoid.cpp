//
//  HTMZoid.cpp
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 06/10/15.
//  added Tiago Ângelo on 06/10/15.
//
//

#include "HTMZoid.h"

HTMZoid::HTMZoid(){
    creatureAuthor  = "Horacio Tome-Marques";
    creatureName    = "Zoid";
    creatureVersion = "Beta";
    // setDate(2014, 12, 22); //Y,M,D
 
    frameCount = 0;
    
    cSize = randInt(20, 30);
    fPos = *new Vec3f(randFloat(-0.004, 0.004), randFloat(-0.004, 0.004), randFloat(-0.004, 0.004));
    fAng = *new Vec3f(randFloat(-0.002, 0.002), randFloat(-0.002, 0.002), randFloat(-0.002, 0.002));
    
    segments = int(randInt(2, 20));
    bLen = randInt(20, 30);
    aFreq = randFloat(0.01, 0.03);
    bOffs = randFloat(5);
    angRange = randFloat(0.6, 0.7);
    numberT = int(randInt(6, 12));
    
}

void HTMZoid::move(){
    
    pos.x += sin(frameCount*fPos.x);
    pos.y += sin(frameCount*fPos.y);
    pos.z += cos(frameCount*fPos.y);

    rot.x = sin(frameCount*fAng.x) / M_2_PI;
    rot.y = sin(frameCount*fAng.y) * M_2_PI/2; //?? HALF_PI;
    rot.z = sin(frameCount*fAng.z) * M_2_PI;
    
}

void HTMZoid::draw(){
    applyTransforms();
    
        // body // can be also manipulated by inputing data (osc)
    gl::color(255, 255, 255, 64);
    gl::lineWidth(1.f);
    gl::begin(GL_LINE);

    gl::drawSolidTriangle(Vec2f(0.f, -20.f), Vec2f(-20.f, 20.f), Vec2f (20.f, 20.f));
    rot.y = (-M_PI/2);
    gl::drawSolidTriangle(Vec2f(0.f, -20.f), Vec2f(-20.f, 20.f), Vec2f (20.f, 20.f));
    rot.y = (-M_PI/4);
    
        // tentacles // can be also manipulated by inputing data (osc)
    
    for (int j=0; j<numberT; j++) {
        Vec2f p = *new Vec2f(bLen, 30.f);
        Vec2f pos = *new Vec2f(cSize/2, 6.f);

        float ang = sin(frameCount*aFreq + j % 9 * bOffs) * angRange;
        float l = bLen;
        gl::begin(GL_LINE);
//        beginShape();
        for (int i=0; i<segments+3; i++) {
            gl::vertex(pos.x, pos.y);
            pos.x += p.x;
            pos.y += p.y;
            p = rotateVec(p, ang);
            p.limit(l);
            l *= 2.93; // can be also manipulated by inputing data (osc)
        }
        gl::end();
        rot.y = (M_PI*2/numberT);
    }
}

//void HTMZoid::rotateVec(){
    Vec2f rotateVec(Vec2<v>, float angle) {
    float c = cos(angle);
    float s = sin(angle);
    return *new Vec2f(v.x*c - v.y*s, v.x*s + v.y*c);
}

