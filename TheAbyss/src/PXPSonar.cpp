//
//  PXPSonar.cpp
//  TheAbyss
//
//  Adapted by Horácio Tomé-Marques, aka, hace, HoMy, on 04/10/15.
//  added Tiago Ângelo on 06/10/15.
//

#include "PXPSonar.h"

PXPSonar::PXPSonar(){
//    creatureAuthor = "Pierre-Xavier Puissant";
//    creatureName = "Sonar";
//    creatureVersion = "1.0";
    //    setDate(2012, 4, 25); //Y,M,D
    frameCount = 1;

    freqMulRot = *new Vec3f(randFloat(-0.0005f, 0.0005f), randFloat(-0.001f, 0.001f), randFloat(-0.0015f, 0.0015f));
    
    freqMulPos = *new Vec3f(randFloat(-0.002f, 0.002f), randFloat(-0.002f, 0.002f), randFloat(-0.002f, 0.002f));
    
    s1 = *new Sphere();
    s1.setRadius(30);
    s2 = *new Sphere();
    s2.setRadius(10);
    
    
//     freqMulSca = *new Vec3f();
//     freqMulSca.x = randFloat(-0.005, 0.005);
//     freqMulSca.y = randFloat(-0.005, 0.005);
//     freqMulSca.z = randFloat(-0.005, 0.005);
}

void PXPSonar::move(){  // isto não está a funcionar bem

    rot.x = sin(frameCount*freqMulRot.x) * M_2_PI; // TWO_PI
    rot.y = sin(frameCount*freqMulRot.y) * M_2_PI; // TWO_PI
    rot.z = sin(frameCount*freqMulRot.z) * M_2_PI; // TWO_PI
    
    pos.x += sin(frameCount*freqMulPos.x);
    pos.y += sin(frameCount*freqMulPos.y);
    pos.z += cos(frameCount*freqMulPos.z);
    
//    applyTransforms(); //????
}

void PXPSonar::draw(){
//    energy = 100;
    time++;
    count++;
    float changeSca = lmap(sin(count*0.15f), -1.f, 1.f, 1.f, 1.5f);
    gl::pushMatrices();
    applyTransforms();

    
    // PULSE ELLIPSE
//    gl::lineWidth(1.f);
//    for (int i = 0; i < bold; i++) {
//        changeAL = (freq-time*fadeSpeed)*(sin((M_PI/bold)*i));
//        gl::color(1.f, 1.f, 1.f, changeAL*2);

//        changeWH = time*0.75f+i;
//        gl::drawStrokedEllipse(Vec2f::zero(), changeWH, changeWH);
//    }
    float changeAL = (freq-time*fadeSpeed) * 0.05480366514879;
    gl::color(1.f, 1.f, 1.f, changeAL);
    float changeWH = time*0.75;
    gl::drawStrokedEllipse(Vec2f::zero(), changeWH, changeWH);
    
    if (time > freq){
        time = 0;
    }
    
    gl::rotate(Vec3f(count*0.011f, count*0.012f, count*0.013f));
    
    gl::enableWireframe();
    gl::color(1.f, 1.f, 1.f, 0.313); // sphere 1 with color + alpha
    //gl::drawSphere( Vec3f::zero(), 30, 6 );
    gl::draw(s1, 6);
    gl::scale(changeSca, changeSca, changeSca);
    gl::color(1.f, 1.f, 1.f, 1.f); // sphere 2 with only color
    //gl::drawSphere(Vec3f::zero(), 10, 5);  // sphere 2 invoking size and geometry detail
    gl::draw(s2, 5);
    
    gl::disableWireframe();
    gl::popMatrices();
    
    frameCount++;
}