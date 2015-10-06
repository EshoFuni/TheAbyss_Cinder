//
//  OTFather.cpp
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 04/10/15.
//  added Tiago Ângelo on 06/10/15.
//

#include "OTFather.h"


OTFather::OTFather(){
    creatureName = "Father";
    creatureAuthor = "Oliviero Tavaglione";
    creatureVersion = "Beta";//    setDate(2011, 5, 7); //Y,M,D

    numSegmenti = floor(randInt(10, 20));
    numTentacoli = 1;
    numPinne = floor(randInt(1, 4));
    distPinne = randFloat(0.2, 0.5);
    l = randInt(80, 160);

//    int numSegmenti = floor(randInt(10, 20));
//    int numTentacoli = 1;
//    int numPinne = floor(randInt(1, 4));
//    float distPinne = randFloat(0.2, 0.5);
//    int l = randInt(80, 160);
    
    //rot = Vec3f(0, 0, 0);

    sm1 = randFloat(-0.005, 0.005);
    sm2 = randFloat(-0.005, 0.005);

//      pVel = *new Vec3f.random3D();
    pVel =Rand::randVec3f();
    rVel =Rand::randVec3f();
    rVel *new Vec3f(randFloat(0.01, 0.03));
//      rVel.mult *new (randFloat(0.01, 0.03));
    noiseVel =Rand::randVec3f();
    noiseVel *new Vec3f(randFloat(0.005, 0.03));
//       noiseVel.mult *new (randFloat(0.005, 0.03));
    float s = randFloat(0.5, 1);
    sca.set(s,s,s);
}

void OTFather::move() {
    count++;
//    pos.add(pVel);
//    rot.add(rVel);
    pos *new Vec3f(pVel);
    rot *new Vec3f(rVel);
    applyTransforms();
}


void OTFather::draw() {
    gl::drawSphere(Vec3f::zero(), l); //? sphere detail
    gl::color( Color::white() );
    //gl::color(255, 255, 255);
    //sphereDetail(detail);
    
    //TESTA
    gl::lineWidth(1.f);
    gl::begin(GL_LINE);
    //fill(255,64);
    //stroke(255);
    //sphere(l);
    
    //ANTENNE
    gl::color(255, 255, 255);
    //stroke(255);
    
    float ly = randFloat(l/2, sin(count * 0.01) * l); // e no processing?
    float lz = randFloat(l, l + (l/1.5)); // e no processing?
    
    // line(0, 0, 0, -l*2, 10, 30); //line(x1, y1, z1, x2, y2, z2)
    gl::drawLine(Vec3f(0, 0, 0), Vec3f(-l*2, 10, 30));
    gl::drawLine(Vec3f(0, 0, 0), Vec3f(-l*2, 10, -30));
    
    
    //PINNE
    //rotateY(-(numPinne-1) * distPinne / 2);
    rotate(0.f, -(numPinne-1) * distPinne / 2, 0.f);  // rotate only Y ?
    for (int k=0; k<numPinne; k++) {
        
        float s = (cos(M_2_PI / (numPinne-1) * k)); //TWO_PI
        s = lmap(s, 1.f, -1.f, 0.9f, 1.f); // map(value, start1, stop1, start2, stop2)
        gl::end();
        gl::pushMatrices();
        // scale(s);
        sca.set(s, s, s);
        
        
        for (int j=0; j<numTentacoli; j++) {
            gl::pushMatrices();
            float a = (mPerlin.noise(count*noiseVel.x + j+k+1)-0.4)*0.782;
            float b = (mPerlin.noise(count*noiseVel.y + j+k+1)-0.5)*0.582;
            float c = (mPerlin.noise(count*noiseVel.z + j+k+1)-0.6)*0.682;
            
            for (int i=0; i<numSegmenti; i++) {
                  //gl::rotate(c, b, a);
                rotate(c, b, a);
                  //rotateZ(a);
                  //rotateY(b);
                  //rotateX(c);
                gl::translate(l*0.9, 0., 0.);
                  //translate(l*0.9, 0, 0);
                gl::scale(0.85, 0.85, 0.85);
                  //scale(0.85, 0.85, 0.85);
                gl::drawCube(Vec3f(0, 0, 0), Vec3f(l, l/2, l));
                  //box(l, l/2, l);
            }
            
            
            gl::popMatrices();
            
            
            //rotateY(TWO_PI/numTentacoli);
        }
        gl::popMatrices();
        //rotateY(distPinne);
        rotate(0.f, distPinne, 0.f);  // rotate only Y ?
    }
}