//
//  Help.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/24/15.
//
//

#include "Help.h"

Help::Help(){
    
}

void Help::init(){
    mParams = ci::params::InterfaceGl::create("TheAbyss Parameters", ci::Vec2i(225, 200) ); // (title, size, color)
    mParams->addParam("Scene Rotation", &mSceneRotation); // ("parameter name", target)

}

void Help::draw(){
    // SHOW UI PARAMETERS
    if (showHelp == true){
        mParams->draw();
    }
    cinder::gl::rotate(mSceneRotation);
}