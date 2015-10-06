//
//  OTFather.cpp
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 04/10/15.
//  added Tiago Ângelo on 06/10/15.//
//

#include "OTFather.h"

OTFather::OTFather(){
    creatureName = "Father";
    creatureAuthor = "Oliviero Tavaglione";
    creatureVersion = "Beta";//    setDate(2011, 5, 7); //Y,M,D
    
    numSegmenti = randInt(10, 20);
    numTentacoli = 1;
    numPinne = randInt(1, 4);
    distPinne = randFloat(0.2, 0.5);
    l = randFloat(80, 160);
    
    sm1 = randFloat(-0.005, 0.005);
    sm2 = randFloat(-0.005, 0.005);
    
    pVel = *new Vec3f(randVec3f());
    rVel = *new Vec3f(randVec3f());
    rVel *= randFloat(0.01, 0.03);
    noiseVel = *new Vec3f(randVec3f());
    noiseVel *= randFloat(0.005, 0.03);
    float s = randFloat(0.5, 1);
    sca.set(s,s,s);
}

void OTFather::move() {
    count++;
    pos += pVel;
    rot += rVel;
}


void OTFather::draw() {
    gl::pushMatrices();
    gl::enableAdditiveBlending();
//    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
//    glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);
//    glEnable(GL_POLYGON_STIPPLE);
//    glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    applyTransforms();
//    gl::enableWireframe();

    
    // TESTA
    gl::color(1.f, 1.f, 1.f, 0.1);
    gl::drawSphere(Vec3f::zero(), l, 16);
    
    //ANTENNE
    gl::color(1.f, 1.f, 1.f, 1.f);
//    float ly = randFloat(l/2, sin(count * 0.01) * l);
//    float lz = randFloat(l, l + (l/1.5)); //
    
    gl::drawLine(Vec3f::zero(), Vec3f(-l*2, 10, 30));
    gl::drawLine(Vec3f::zero(), Vec3f(-l*2, 10, -30));
    
    //PINNE
    gl::color(1.f, 1.f, 1.f, 0.39216);
    gl::rotate(Vec3f(0.f, -(numPinne-1) * distPinne / 2, 0.f));
    
    
    for (int k=0; k<numPinne; k++) {
        
        float s = (cos(M_2_PI / (numPinne-1) * k));
        s = lmap(s, 1.f, -1.f, 0.9f, 1.f);
        gl::pushMatrices();
        gl::scale(Vec3f(s, s, s));
        // scale(s);
        //sca.set(s, s, s);
        
        
        for (int j=0; j<numTentacoli; j++) {
            gl::pushMatrices();
            float a = (mPerlin.noise(count*noiseVel.x + j+k+1)-0.4)*0.782;
            float b = (mPerlin.noise(count*noiseVel.y + j+k+1)-0.5)*0.582;
            float c = (mPerlin.noise(count*noiseVel.z + j+k+1)-0.6)*0.682;
            
            for (int i=0; i<numSegmenti; i++) {
                gl::rotate(Vec3f(c, b, a));
                gl::translate(l*0.9, 0., 0.);
                gl::scale(0.85, 0.85, 0.85);
                gl::drawCube(Vec3f::zero(), Vec3f(l, l/2, l));
                //box(l, l/2, l);
            }
            
            gl::popMatrices();
            
        }
        gl::popMatrices();
        //rotateY(distPinne);
        gl::rotate(Vec3f(0.f, distPinne, 0.f));
    }
//    gl::disableWireframe();
    gl::popMatrices();
}