//
//  AbyssGUI.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/24/15,
//  added Horácio Tomé-Marques on 7/24/15,
//  and João Menezes one of these days!;–}.
//

#include "AbyssGUI.h"

AbyssGUI::AbyssGUI(){
    
}

// light with specific direction controller/xyz specific
// TODO enable the light — and objects — position/xyz specific
// TODO code leveraging
// don´t forget to comment
void AbyssGUI::setLightDirection( Vec3f direction ) // light direction
{
    mLightDirection = direction;
}

void AbyssGUI::init(){
    mParams = ci::params::InterfaceGl::create("TheAbyss Parameters", ci::Vec2i(225, 200) ); // (title, size, color)
    mParams->addParam("Scene Rotation", &mSceneRotation); // ("parameter name", target)
    mParams->addSeparator("Lights"); //added line separator
       // Added first light
        mLightDirection = Vec3f( 0, 0, -1 ); // light controlling
        std::function<void( Vec3f )> setter	= std::bind( &AbyssGUI::setLightDirection, this, std::placeholders::_1 );
        std::function<Vec3f ()> getter = std::bind( &AbyssGUI::getLightDirection, this );
        mParams->addParam( "Light One", setter, getter );
}

void AbyssGUI::draw(){
    // SHOW UI PARAMETERS
    if (showAbyssGUI == true){
        mParams->draw();
    }
    cinder::gl::rotate(mSceneRotation); //scene
    // light(s)
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    GLfloat lightPosition[] = { -mLightDirection.x, -mLightDirection.y, -mLightDirection.z, 0 };
    glLightfv( GL_LIGHT0, GL_POSITION, lightPosition );
}