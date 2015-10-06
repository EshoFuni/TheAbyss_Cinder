//
//  Cam.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/24/15.
//
//  Camera class
//

#include "Cam.h"
#include "cinder/app/AppNative.h"
#include "cinder/Vector.h"

using namespace ci;

#include <vector>

Cam::Cam(){
    // INIT CAMERA VARIABLES
    mEye = Vec3f(0.f, 0.f, 500.f);
    mCenter = Vec3f::zero();
    mUp = Vec3f::yAxis();
}
void Cam::init(){
    mCamera.setPerspective(60.f, app::getWindowAspectRatio(), 5.f, 3000.f);
    // app namespace cannot be called from the constructor (I guess there is no app at that point)
}

void Cam::setCam(){
    // SET CAMERA
    mCamera.lookAt(mEye, mCenter, mUp);
    gl::setMatrices(mCamera);
}

