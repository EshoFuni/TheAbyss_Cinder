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
using std::list;

CreatureManager::CreatureManager(){
    // INIT UI PARAMETERS VARIABLES

}

void CreatureManager::update(){
    for(list<TACreatureExample>::iterator p = mCreatures.begin(); p != mCreatures.end(); p++ ){
        p->move();
    }
}

void CreatureManager::draw(){
    for (list<TACreatureExample>::iterator p = mCreatures.begin(); p != mCreatures.end(); p++) {
        p->draw();
    }
}

void CreatureManager::addCreature(){
    mCreatures.push_back(TACreatureExample());
}

void CreatureManager::removeCreature(){
    if (mCreatures.size() !=  0){ // prevent crash when popping back from an empty list
        mCreatures.pop_back();
    }
    
}