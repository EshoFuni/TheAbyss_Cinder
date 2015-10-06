//
//  CreatureManager.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
/*
* The core class.
* Takes care of instantiating creatures and makes them live and die.
*/
//

#include "CreatureManager.h"

CreatureManager::CreatureManager(){
    // INIT UI PARAMETERS VARIABLES
    mClasses = {"AGWorm", "PXPSonar"};
}

void CreatureManager::update(){
//    for(vector<SuperCreature*>::iterator p = mCreatures.begin(); p != mCreatures.end(); p++ ){
//        p->move();
//    }
    for(int i = 0; i<mCreatures.size(); i++){
        mCreatures[i]->move();
    }
}

void CreatureManager::draw(){
//    for (vector<SuperCreature*>::iterator p = mCreatures.begin(); p != mCreatures.end(); p++) {
//        p->draw();
//    }
    for(int i = 0; i<mCreatures.size(); i++){
        mCreatures[i]->draw();
    }

}


// add random creature
void CreatureManager::addRandomCreature(){
    int creature = randInt( mClasses.size() );
    
    switch (creature) {
        case 0:
            mCreatures.push_back( new AGWorm() );
            break;
            
//        case 1:
//            mCreatures.push_back( new HTMZoid() );
//            break;
//            
//        case 2:
//            mCreatures.push_back( new TACreatureExample() );
        
        case 1:
            mCreatures.push_back( new PXPSonar() );
        default:
            break;
    }
}

// remove creature at the end of mCreatures list
void CreatureManager::removeLastCreature(){
    if (mCreatures.size() !=  0){ // prevent crash when popping back from an empty list
        mCreatures.pop_back();
    }
    
}

void CreatureManager::compPlus(){
    for(int i = 0; i<mCreatures.size(); i++){
        mCreatures[i]->complexPlus();
    }
}

void CreatureManager::compMinus(){
    for(int i = 0; i<mCreatures.size(); i++){
        mCreatures[i]->complexMinus();
    }
}

void CreatureManager::addWorm(){
    mCreatures.push_back( new AGWorm() );
}

void CreatureManager::addPXP(){
    mCreatures.push_back( new PXPSonar() );
}


