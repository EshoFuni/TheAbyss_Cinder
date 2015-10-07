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

void AbyssGUI::setLightDirection1( Vec3f direction1 ) // light1 direction
{
    mLightDirection1 = direction1;
}

void AbyssGUI::init(){
    mParams = ci::params::InterfaceGl::create("TheAbyss Parameters", ci::Vec2i(225, 200) ); // (title, size, color)
    mParams->addParam("Scene Rotation", &mSceneRotation); // ("parameter name", target)
    mParams->addSeparator("Lights"); //added line separator
    
    // Added first light
    mLightDirection = Vec3f( 90.f, -50.f, -50.f ); // light controlling
    std::function<void( Vec3f )> setter	= std::bind( &AbyssGUI::setLightDirection, this, std::placeholders::_1 );
    std::function<Vec3f ()> getter = std::bind( &AbyssGUI::getLightDirection, this );
    mParams->addParam( "Light One", setter, getter );
    
    mLightDirection1 = Vec3f( -90.f, 50.f, 50.f ); // light1 controlling
    std::function<void( Vec3f )> setter1 = std::bind( &AbyssGUI::setLightDirection1, this, std::placeholders::_1 );
    std::function<Vec3f ()> getter1 = std::bind( &AbyssGUI::getLightDirection1, this );
    mParams->addParam( "Light Two", setter1, getter1 );
    
}

void AbyssGUI::draw(){
    
    cinder::gl::rotate(mSceneRotation); //scene
    
    // light(s)
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    glEnable( GL_LIGHT1 );
    
    GLfloat light0_Position[] = { -mLightDirection.x, -mLightDirection.y, -mLightDirection.z, 0 };
    GLfloat light1_Position1[] = { -mLightDirection1.x, -mLightDirection1.y, -mLightDirection1.z, 0 };
    
    glLightfv( GL_LIGHT0, GL_POSITION, light0_Position );
    glLightfv( GL_LIGHT1, GL_POSITION, light1_Position1 );
    
    // SHOW UI PARAMETERS
    if (showAbyssGUI == true){
        mParams->draw();
    }
    
}