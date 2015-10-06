//
//  PXPSonar.cpp
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 04/10/15.
//  added Tiago Ângelo on 06/10/15.
//

#include "PXPSonar.h"

PXPSonar::PXPSonar(){
    creatureAuthor = "Pierre-Xavier Puissant";
    creatureName = "Sonar";
    creatureVersion = "1.0";
    //    setDate(2012, 4, 25); //Y,M,D
    frameCount = 0;

    freqMulRot = *new Vec3f();
    freqMulRot.x = randFloat(-0.0005f, 0.0005f);
    freqMulRot.y = randFloat(-0.001f, 0.001f);
    freqMulRot.z = randFloat(-0.0015f, 0.0015f);
    
    freqMulPos = *new Vec3f();
    freqMulPos.x = randFloat(-0.002f, 0.002f);
    freqMulPos.y = randFloat(-0.002f, 0.002f);
    freqMulPos.z = randFloat(-0.002f, 0.002f);
    
//     freqMulSca = *new Vec3f();
//     freqMulSca.x = randFloat(-0.005, 0.005);
//     freqMulSca.y = randFloat(-0.005, 0.005);
//     freqMulSca.z = randFloat(-0.005, 0.005);
}

void PXPSonar::move(){  // isto não está a funcionar bem
    rot.x = sin(frameCount*freqMulRot.x) * M_2_PI; // TWO_PI
    rot.y = sin(frameCount*freqMulRot.y) * M_2_PI; // TWO_PI
    rot.z = sin(frameCount*freqMulRot.z) * M_2_PI; // TWO_PI
    
    //rot.rotateX(0.f);
    //rot.rotateY(0.f);
    //rot.rotateZ(0.f);
    
    pos.x += sin(frameCount*freqMulPos.x);
    pos.y += sin(frameCount*freqMulPos.y);
    pos.z += cos(frameCount*freqMulPos.z);
    
    applyTransforms(); //????
    
}

void PXPSonar::draw(){
    int energy = 100; // e no processing?
    time++;
    count++;
    float changeWH;
    float changeAL;
    float changeSca = lmap(sin(count*0.15f), -1.f, 1.f, 1.f, 1.5f);

    //gl::color( Color::white() );
    gl::lineWidth(1.f);
    gl::begin(GL_LINE);
    for (int i = 0; i < bold; i++) {
        changeAL = (freq-time*fadeSpeed)*(sin((M_PI/bold)*i));
        gl::color(1.f, 1.f, 1.f, changeAL*2);
        //stroke(255, 255, 255, changeAL*2); // with color rgb + alpha
        changeWH = exp(sqrt(time*0.75f))+i;
        gl::drawStrokedEllipse(Vec2f(0.f, 0.f), changeWH, changeWH);
        //ellipse (0, 0, changeWH, changeWH); //x, y, w, h
        gl::end();
    }
    
    // gl::rotate(Vec3f(count*0.011f, count*0.012f, count*0.013f));
    rot = *new Vec3f(count*0.011f, count*0.012f, count*0.013f);

    gl::pushMatrices();
    cinder::gl::enableWireframe();
    gl::color(255, 255, 255, 80); // sphere 1 with color + alpha
//    gl::drawSphere( Vec3f(0.f, 0.f, 0.f), 30, 6 );
    gl::drawSphere(Vec3f::zero(), 30, 6); // sphere 1 invoking size and geometry detail
    sca = *new Vec3f(changeSca, changeSca, changeSca);
//    gl::scale(changeSca, changeSca, changeSca);
    gl::color(255, 255, 255); // sphere 2 with only color
//    gl::drawSphere( Vec3f(0.f, 0.f, 0.f), 10, 1 );
    gl::drawSphere(Vec3f::zero(), 10, 1);  // sphere 2 invoking size and geometry detail
    gl::disableWireframe();
    gl::popMatrices();
    frameCount++;
}