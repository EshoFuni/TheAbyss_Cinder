//
//  BCIWave.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 9/28/15.
//
//

#include "BCIWave.h"

BCIWave::BCIWave(){}

BCIWave::BCIWave(int port, bool verb){
    listener.setup(port);
    verbose = verb;
}

void BCIWave::update(){
    while( listener.hasWaitingMessages() ) {
        cinder::osc::Message message;
		listener.getNextMessage( &message );
        
        if( message.getAddress() == "/wave1/"){
            amp = message.getArgAsFloat(0);
            
            if(verbose == true)
                cinder::app::console() << "wave1 value = " << message.getArgAsFloat(0) << endl;
        }
        else {
            cinder::app::console() << "UNEXPECTED OSC MESSAGE !!!" << endl;;
        }


    }
}

void BCIWave::draw(){
    
}