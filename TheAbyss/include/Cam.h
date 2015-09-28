//
//  Cam.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/24/15.
//
//

#ifndef __TheAbyss__Cam__
#define __TheAbyss__Cam__

#pragma once
#include "cinder/Camera.h"

using namespace ci;

class Cam{
public:

    Cam();
    void init();
    void setCam();

    // CAMERA VARIABLES
    // for camera related information check file://localhost/Applications/cinder_0.8.6_mac/docs/html/flocking_chapter1.html
    CameraPersp mCamera; // the "m" prefix means this is a member variable (in opposition to local variables)
    Vec3f mEye; // where the camera is positioned
    Vec3f mCenter; // where the camera is pointing to
    Vec3f mUp; // what is the upwards direction (in this case the Y axis)

};

#endif /* defined(__TheAbyss__Cam__) */
