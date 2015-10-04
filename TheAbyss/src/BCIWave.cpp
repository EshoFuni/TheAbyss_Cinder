//
//  BCIWave.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 9/28/15.
//
//

#include "BCIWave.h"

BCIWave::BCIWave(){}

BCIWave::BCIWave(int port, string address, string eAddress,int offset, float maxAmp, float speed, int size, bool verbose){
    listener.setup(port);
    waveAddress = address;
    mVerbose = verbose;
    mSize = size;
    mOffset = offset;
    mMaxAmp = maxAmp;
    mSpeed = speed;
    mTrail = 1.f/mSize; // manual init (FOR NOW)

    // INIT mAmp, yPos and mColor
    for (int i = 0; i < mSize; i++){
        mAmp.push_back(0.f);
        yPos.push_back(0.f);
        mColor.push_back(1 - i * mTrail);
        //app::console() << mColor.at(i) << endl;
    }
    
    // EVENT TRIGGER VARIABLES
    eventTrigger = 0; // 0 - no trigger, 1 - trigger, 2 - drawing horizontal, 3 - drawing vertical
    eventAddress = eAddress;
    eventColor = 1.f;
    eventSpeed = 2.f;
    
    // OTHER VARIABLES
    width = app::getWindowWidth();
    height = app::getWindowHeight();
}


void BCIWave::update(){
    // READ OSC DATA
    while( listener.hasWaitingMessages() ) {
        cinder::osc::Message message;
		listener.getNextMessage( &message );
        
        if( message.getAddress() == waveAddress){
            // UPDATE AMP VALUE
            rotate(mAmp.begin(), mAmp.end()-1, mAmp.end()); // right shift vector
            mAmp.at(0) = message.getArgAsFloat(0) * mMaxAmp + mOffset; // insert new value at pos(0)
            // UPDATE Y-POSITION VALUE
            rotate(yPos.begin(), yPos.end()-1, yPos.end()); // right shift vector
            yPos.at(0) = int(yPos.at(1) + mSpeed) % height; // USE THIS for wave() GL_LINE mode

            
            if(mVerbose == true){
                cinder::app::console() << "wave1 value = " << message.getArgAsFloat(0) << endl;
            }
        }
        if (message.getAddress() == eventAddress && eventTrigger == 0){
            eventTrigger = 1;
            if(mVerbose == true){
                cinder::app::console() << eventAddress << message.getArgAsFloat(0) << endl;
            }
        }
        if (message.getAddress() != eventAddress && message.getAddress() != waveAddress){
            cinder::app::console() << "UNEXPECTED OSC MESSAGE !!!" << endl;
        }
    }
}


// WORKING! - GL_LINES mode ( uglier but faster! note that mSpeed>1 doesn't work as expected...)
void BCIWave::wave(){
    // properties
    gl::lineWidth(1.0f);
    gl::color(1.f, 0.f, 0.f, 0.f);
    
    gl::begin(GL_LINES);
    //gl::vertex(mAmp.back(), yPos.back());
    
    for (int i = mSize-1; i > 0; i-- ){
        gl::color(1.f, 1.f, 1.f, mColor.at(i));
        gl::vertex(mAmp.at(i), yPos.at(i));
        gl::color(1.f, 1.f, 1.f, mColor.at(i-1));
        gl::vertex(mAmp.at(i-1), yPos.at(i));
    }
    gl::end();
}

void BCIWave::event(){
    if( eventTrigger == 1){
        eventXStart = mAmp.front();
        eventYStart = yPos.front();
        eventX = mAmp.front();
        eventY = yPos.front();
        eventTrigger = 2;
        eventColor = 1.f;
    }
    if(eventTrigger == 2){ // draw horizontal line
        eventX+=eventSpeed;
        gl::color(1.f, 1.f, 1.f, eventColor);
        gl::drawLine(Vec2f(eventXStart, eventYStart), Vec2f(eventX, eventYStart));
        eventColor -= mTrail;
        if(eventX > width/2){
            eventTrigger = 3;
        }
    }

    if(eventTrigger == 3){ // draw vertical line
        if(eventYStart < height/2){
            eventY += eventSpeed;
            gl::color(1.f, 1.f, 1.f, eventColor);
            gl::drawLine(Vec2f(eventXStart, eventYStart), Vec2f(eventX, eventYStart));
            gl::drawLine(Vec2f(eventX, eventYStart), Vec2f(eventX, eventY));
            eventColor -= mTrail;
            if(eventY > height/2){
                eventTrigger = 0;
            }
        }
        else {
            eventY -= eventSpeed;
            gl::color(1.f, 1.f, 1.f, eventColor);
            gl::drawLine(Vec2f(eventXStart, eventYStart), Vec2f(eventX, eventYStart));
            gl::drawLine(Vec2f(eventX, eventYStart), Vec2f(eventX, eventY));
            eventColor -= mTrail;
            if(eventY < height/2){
                eventTrigger = 0;
            }
        }
        
    }
}

void BCIWave::draw(){
    // disable 
    //gl::disableAlphaBlending();
    glDisable( GL_LIGHTING );
    glDisable( GL_LIGHT0 );
    // enable 2D drawing
    gl::setMatricesWindow( app::getWindowSize() );
    
    wave();
    event();
    
}

// NOT WORKING! - GL_LINE_STRIP MODE
//void BCIWave::wave(){
//    // properties
//    gl::lineWidth(2.f);
//    Vec3f c  = randVec3f();
//
//    gl::begin(GL_LINE_STRIP);
//
//    //gl::vertex( mAmp.front(), yPos.front() ); // moveTo front
//
//    for (int i = 0; i < mSize-2; i++) {
//        gl::color(1.f, c.y, c.z);
//        if(yPos.at(i) < height && yPos.at(i+1) < height){
//            gl::vertex(mAmp.at(i), yPos.at(i));
//        }
//        else {
//            yPos.at(i+1) = height - yPos.at(i+1);
//            yPos.at(i) = height - yPos.at(i) + yPos.at(i+1);
//            gl::end();
//            gl::vertex(mAmp.at(i), yPos.at(i));
//        }
//    }
//    gl::vertex(mAmp.back(), yPos.back());
//
//
//    gl::end();
//}


/* Vector version3 : very very close
void BCIWave::wave(){
    // READ OSC DATA
    while( listener.hasWaitingMessages() ) {
        cinder::osc::Message message;
		listener.getNextMessage( &message );

        if( message.getAddress() == mAddress){
            // UPDATE AMP VALUE
            rotate(mAmp.begin(), mAmp.end()-1, mAmp.end()); // right shift vector
            mAmp.at(0) = message.getArgAsFloat(0) * mMaxAmp; // insert new value at pos(0)

            if(mVerbose == true){
                cinder::app::console() << "wave1 value = " << message.getArgAsFloat(0) << endl;
            }
        }
        else {
            if(mVerbose == true)
                cinder::app::console() << "UNEXPECTED OSC MESSAGE !!!" << endl;;
        }
    }

    // DRAW WAVE
    //mWave.clear();
    gl::begin(GL_LINE_STRIP);
    //mWave.moveTo( mOffset + mAmp.back(), yPos.back() );
    gl::vertex(mOffset + mAmp.back(), yPos.back());

    // UPDATE Y-POSITION VALUE
    rotate(yPos.begin(), yPos.end()-1, yPos.end());
    yPos.at(0) = yPos.at(1) + mSpeed;
    // RESET Y POSITION WHEN ALL VALUES ARE BIGGER THAN SCREEN HEIGHT
    if (yPos.front() > height){
        for (int i = 0; i < mSize; i++){
            yPos.at(i) = 0.f;
        }
        //mWave.clear();
        gl::end();
        gl::begin(GL_LINE_STRIP);
        //mWave.moveTo( mOffset + mAmp.back(), yPos.back() );
        gl::vertex( mOffset + mAmp.back(), yPos.back() );
        

    }

    // LINE TO
    for(int i = mSize-2; i > -1; i--){
        //mWave.lineTo( mOffset + mAmp.at(i), yPos.at(i) );
        gl::vertex( mOffset + mAmp.at(i), (int)yPos.at(i) % height );
    }

    gl::lineWidth(2.f);
    gl::color(1.f, 0.f, 0.f);
    //gl::draw(mWave);
    gl::end();
}
*/

/* Vector version2 : pretty close*/
//void BCIWave::wave(){
//    // READ OSC DATA
//    while( listener.hasWaitingMessages() ) {
//        cinder::osc::Message message;
//		listener.getNextMessage( &message );
//        
//        if( message.getAddress() == mAddress){
//            // UPDATE AMP VALUE
//            rotate(mAmp.begin(), mAmp.end()-1, mAmp.end()); // right shift vector
//            mAmp.at(0) = message.getArgAsFloat(0) * mMaxAmp; // insert new value at pos(0)
//            
//            if(mVerbose == true){
//                cinder::app::console() << "wave1 value = " << message.getArgAsFloat(0) << endl;
//            }
//        }
//        else {
//            if(mVerbose == true)
//                cinder::app::console() << "UNEXPECTED OSC MESSAGE !!!" << endl;;
//        }
//    }
//    
//    // DRAW WAVE
//    mWave.clear();
//    mWave.moveTo( mOffset + mAmp.back(), yPos.back() );
//    //app::console() << "moveTo: " << mOffset + mAmp.back() << " " << yPos.back() << endl;
//    
//    // UPDATE Y-POSITION VALUE
//    rotate(yPos.begin(), yPos.end()-1, yPos.end());
//    yPos.at(0) = yPos.at(1) + mSpeed;
//    // RESET Y POSITION WHEN ALL VALUES ARE BIGGER THAN SCREEN HEIGHT
//    if (yPos.back() > height){
//        for (int i = 0; i < mSize; i++){
//            yPos.at(i) = 0.f;
//        }
//        mWave.clear();
//        mWave.moveTo( mOffset + mAmp.back(), yPos.back() );
//        
//    }
//    
//    // LINE TO
//    for(int i = mSize-2; i > -1; i--){
//        mWave.lineTo( mOffset + mAmp.at(i), yPos.at(i) );
//        //app::console() << "lineTo: " << mOffset + mAmp.at(i) << " " << yPos.at(i) << endl;
//    }
//    
//    
//    gl::lineWidth(2.f);
//    gl::color(1.f, 0.f, 0.f);
//    gl::draw(mWave);
//    
//}

/* Vector version 1
void BCIWave::wave(){
    // UPDATE COLOR
    
    
    // UPDATE Y-POSITION VALUE
    rotate(yPos.begin(), yPos.begin()+1, yPos.end());
    yPos.at(0) = yPos.at(1) + mSpeed;
    if (yPos.at(0) > height){
        yPos.at(0) = 0;
        
        mWave.clear();
        mWave.moveTo(mOffset + mAmp.at(1), yPos.back());
    }
    // SET PATH
    mWave.lineTo(mOffset + mAmp.at(0), yPos.at(0));
    gl::lineWidth(2.f);
    gl::color(1.f, 0.f, 0.f);
    gl::draw(mWave);

}*/

/* Two-point version
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
} */

//void BCIWave::update(){
//    while( listener.hasWaitingMessages() ) {
//        cinder::osc::Message message;
//		listener.getNextMessage( &message );
//
//        if( message.getAddress() == mAddress){
//            //pAmp = mAmp; // set previous amp value
//
//            // AMP: INSERT NEW VALUE IN POSITION 0 AND ERASE LAST INDEX
//            /*vector<float>::iterator ai = mAmp.begin(); // amplitude iterator
//            mAmp.insert(ai, message.getArgAsFloat(0) * mMaxAmp); // insert OSC value
//            ai = mAmp.end();
//            mAmp.erase(ai);
//
//            // Y POS: INSERT NEW VALUE IN POSITION 0 AND ERASE LAST INDEX
//            vector<float>::iterator yi = mAmp.begin(); // y-position iterator
//            if( yPos.back() < height){
//                yPos.insert(yi, yPos.front() += mSpeed); // update y-position
//            }
//            else {
//                yPos.insert(yi, 0.); // update y-position if y > screenHeight
//            }
//            yi = mAmp.end();
//            mAmp.erase(yi);
//            */
//
//            // UPDATE AMP VALUE
//            rotate(mAmp.begin(), mAmp.end()-1, mAmp.end()); // right shift vector
//            mAmp.at(0) = message.getArgAsFloat(0) * mMaxAmp; // insert new value at pos(0)
//
//            if(mVerbose == true){
//                cinder::app::console() << "wave1 value = " << message.getArgAsFloat(0) << endl;
//            }
//        }
//        else {
//            if(mVerbose == true)
//            cinder::app::console() << "UNEXPECTED OSC MESSAGE !!!" << endl;;
//        }
//    }
//}
