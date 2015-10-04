//
//  AbyssGUI.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/24/15,
//  added Horácio Tomé-Marques on 7/24/15,
//  and João Menezes one of these days!;–}.
//

#ifndef __TheAbyss__AbyssGUI__
#define __TheAbyss__AbyssGUI__

#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/app/AppNative.h"
#include "cinder/params/Params.h"
#include "cinder/Quaternion.h"
#include <functional>

using namespace ci;
using namespace ci::app;

// changed name to AbyssGUI > instead of original Help)
class AbyssGUI{
public:
    AbyssGUI();
    void init();
    void draw();
    //std::string mString;
    
    // UI PARAMETERS VARIABLES
    ci::params::InterfaceGlRef mParams; // parameters member variable (console)
    ci::Quatf mSceneRotation; // scene rotation variable
    void setLightDirection( Vec3f direction ); // parameters member variable (light)
    Vec3f getLightDirection() { return mLightDirection; }
    Vec3f mLightDirection;
    bool showAbyssGUI = true;
};

#endif /* defined(__TheAbyss__AbyssGUI__) */
