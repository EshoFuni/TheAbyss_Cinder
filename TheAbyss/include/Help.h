//
//  Help.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/24/15.
//
//

#ifndef __TheAbyss__Help__
#define __TheAbyss__Help__

#pragma once
#include "cinder/params/Params.h"
#include "cinder/Quaternion.h"

class Help{
public:
    Help();
    void init();
    void draw();
    
    // UI PARAMETERS VARIABLES
    ci::params::InterfaceGlRef mParams; // parameters member variable
    ci::Quatf mSceneRotation; // scene rotation variable
    bool showHelp = true;
    
};

#endif /* defined(__TheAbyss__Help__) */
