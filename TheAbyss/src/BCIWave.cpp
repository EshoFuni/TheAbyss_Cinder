//
//  BCIWave.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 9/28/15.
//
//

#include "BCIWave.h"

BCIWave::BCIWave(){}

BCIWave::BCIWave(int port, string address, int offset, float maxAmp, float speed, bool verbose){
    listener.setup(port);
    mAddress = address;
    mVerbose = verbose;
    
    mOffset = offset;
    mAmp = 0.f; // init amp
    pAmp = 0.f; // init previous amp value
    mMaxAmp = maxAmp;
    mSpeed = speed;
    yPos = mSpeed; // init y position
    pYPos = 0.f; // init previous y position

    
    width = app::getWindowWidth();
    height = app::getWindowHeight();

    mColor = {1.f, 1.f, 1.f, 1.f};
    
}

void BCIWave::update(){
    while( listener.hasWaitingMessages() ) {
        cinder::osc::Message message;
		listener.getNextMessage( &message );
        
        if( message.getAddress() == mAddress){
            pAmp = mAmp; // set previous amp value
            mAmp = message.getArgAsFloat(0) * mMaxAmp; // read osc wave amp value
            
            if(mVerbose == true){
                cinder::app::console() << "wave1 value = " << message.getArgAsFloat(0) << endl;
            }
        }
        else {
            cinder::app::console() << "UNEXPECTED OSC MESSAGE !!!" << endl;;
        }


    }
}

void BCIWave::draw(){
    // disable 
    gl::disableAlphaBlending();
    glDisable( GL_LIGHTING );
    glDisable( GL_LIGHT0 );
    // enable 2D drawing
    gl::setMatricesWindow( app::getWindowSize() );
    
//    mWave.clear();
//    mWave.moveTo( mOffset + mAmp, 0);
//    mWave.lineTo( mOffset + mAmp, height);
    wave();
    
    gl::draw(mWave);

}

void BCIWave::wave(){
    // SET PATH
    mWave.clear();
    mWave.moveTo( mOffset + pAmp, pYPos); // move to previous point
    mWave.lineTo( mOffset + mAmp, yPos); // draw to current point
    // MOVE
    pYPos = yPos; // store previous y value
    yPos += mSpeed; // increment cureent y
    // RESET
    if(yPos > height){ // reset when wave reaches the end of the screen
        yPos = mSpeed;
        pYPos = 0.f;
    }
}