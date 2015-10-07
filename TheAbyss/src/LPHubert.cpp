//
//  LPHubert.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 10/7/15.
//
//

#include "LPHubert.h"

LPHubert::LPHubert(){
    creatureAuthor ="Laura Perrenoud";
    creatureName ="Hubert";
    creatureVersion ="1.0";
//    setDate(2012, 4, 26);
    
    //Mouvement alétoire
    freqMulPos = *new Vec3f();
    freqMulPos *= randFloat(-0.02, 0.02);
    
    freqMulAng = *new Vec3f();
    freqMulAng *= randFloat(-0.005, 0.005);
    
    //Créature random
    num = 10;
    cSize = randFloat(6, 30);
    bLen = randFloat(5, 15);
    aFreq = randFloat(0.01, 0.02);
    bOffs = randFloat(5);
    angRange = randFloat(0.3, 0.6);
    numberT = randInt(3, 20);
    numberSeg = randInt(3, 7);
    elSize = 5;
    val2div = randInt(1, 3);
    scaR = randFloat(3, 15.2); // 0.3 1.52
    sca *= scaR;
//    sca.x = scaR;
//    sca.y = scaR;
//    sca.z = scaR;
}

void LPHubert::move() {
    count++;
    
    pos.x += sin(count*freqMulPos.x);
    pos.y += sin(count*freqMulPos.y);
    pos.z += sin(count*freqMulPos.z);
    
    rot.x = sin(count*freqMulAng.x) * M_2_PI;
    rot.y = sin(count*freqMulAng.y) * M_2_PI;
    rot.z = sin(count*freqMulAng.z) * M_2_PI;
    
    //    SuperCreature x = getNearest("Hubert");
    //    if (x != null) {
    //      float dis = dist(x.pos.x, x.pos.y, x.pos.z, pos.x, pos.y, pos.z);
    //      if (dis < 320 && !isAngry) {
    //        isAngry = true;
    //
    //        for (int i=0; i<random(3, 6); i++) {
    //          missiles.add(new Missile(pos, x));
    //        }
    //      }
    //      else {
    //        isAngry = false;
    //      }
    //    }
    //    launchMissile();
}

void LPHubert::draw() {
    gl::pushMatrices();
    applyTransforms();
    gl::lineWidth(4.f);
    
//    strokeWeight(1);
//    noFill();
//    stroke(255, 150);
    gl::color(1.f, 1.f, 1.f, 1.f);
    gl::drawStrokedCube(Vec3f::zero(), Vec3f(150, 150 ,150));
    
    float val2 = sin(count*aFreq*3)*2;
    
    float a1 = sin(count*aFreq + bOffs) * angRange;
    float a2 = sin(count*aFreq) * angRange;
    
    for (int j=0; j<numberT; j++) {
        
        Vec2f p = *new Vec2f(bLen, 0);
        Vec2f pos = *new Vec2f(cSize/6, 0);
        float ang = (j % 2 == 0) ? a1 : a2;
        float l = bLen;
        
        for (int i=0; i<numberSeg; i++) {
            if (i<numberSeg-2) {
                gl::pushMatrices();
                gl::translate(pos.x + pos.x, pos.y+pos.y, 0.f);
                gl::drawStrokedCube(Vec3f::zero(), Vec3f(3+val2, 3+val2, 3+val2));
//                box(3+val2);
                gl::popMatrices();
            }
            
            gl::drawLine(pos, pos+p);
            pos.x += p.x;
            pos.y += p.y;
            p = rotateVec(p, ang+(val2 * 0.1));
            p.limit(l);
            l *= 0.99;
            //l *= 0.93;
        }
        gl::rotate(Vec3f(0, M_2_PI/numberT,0));
//        rotateY(PI*2/numberT);
    }
    
    gl::popMatrices();
}

Vec2f LPHubert::rotateVec(Vec2f v, float angle){
    float c = cos(angle);
    float s = sin(angle);
    return *new Vec2f(v.x*c - v.y*s, v.x*s + v.y*c);
}