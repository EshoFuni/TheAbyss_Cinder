//
//  CreatureManager.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15,
//  added Horácio Tomé-Marques on 7/24/15,
//  and João Menezes one of these days!;–}.
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
// temporary testing with more than one creature
void CreatureManager::update(){
    for(list<TACreatureExample>::iterator p = mCreatures0.begin(); p != mCreatures0.end(); p++ ){
        p->move();
            // added
            for(list<HTMPreGelly>::iterator p = mCreatures1.begin(); p != mCreatures1.end(); p++ ){
            p->move();
        }
    }
}

void CreatureManager::draw(){
    for (list<TACreatureExample>::iterator p = mCreatures0.begin(); p != mCreatures0.end(); p++) {
        p->draw();
            // added
            for (list<HTMPreGelly>::iterator p = mCreatures1.begin(); p != mCreatures1.end(); p++) {
            p->draw();
        }
    }
}

void CreatureManager::addCreature(){
    mCreatures0.push_back(TACreatureExample());
        // added
        mCreatures1.push_back(HTMPreGelly());
}

void CreatureManager::removeCreature(){
    if (mCreatures0.size() !=  0){ // prevent crash when popping back from an empty list
        mCreatures0.pop_back();
            // added
            if (mCreatures1.size() !=  0){ // prevent too?
            mCreatures1.pop_back();
        }
    
    }
}

// test HTMPreGelly solo // disable more than one creature
//void CreatureManager::update(){
//    for(list<HTMPreGelly>::iterator p = mCreatures.begin(); p != mCreatures.end(); p++ ){
//        p->move();
//    }
//}
//
//void CreatureManager::draw(){
//    for (list<HTMPreGelly>::iterator p = mCreatures.begin(); p != mCreatures.end(); p++) {
//        p->draw();
//    }
//}
//
//void CreatureManager::addCreature(){
//    mCreatures.push_back(HTMPreGelly());
//}
//
//void CreatureManager::removeCreature(){
//    if (mCreatures.size() !=  0){ // prevent crash when popping back from an empty list
//        mCreatures.pop_back();
//    }
//    
//}