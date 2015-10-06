//
//  CreatureManager.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
//
//

#ifndef __TheAbyss__CreatureManager__
#define __TheAbyss__CreatureManager__

#pragma once
#include <vector>
#include "cinder/Rand.h"

#include "TACreatureExample.h"
#include "AGCubus.h"
#include "SuperCreature.h"
#include "HTMPreGelly.h"
#include "AGWorm.h"
#include "PXPSonar.h" //test

using namespace ci;

class CreatureManager{
public:
    CreatureManager();
    void update();
    void draw();

    void addRandomCreature();
    void removeLastCreature();
    void addGelly(); // FOR TESTING ONLY!!!!!!
    void addWorm(); // FOR TESTING ONLY!!!!!!
    void addPXPSonar(); // FOR TESTING ONLY!!!!!!
    
    std::vector<SuperCreature*> mCreatures; // creature container
    std::list<string> mClasses; //list of all creature classes
    

private:
    
};

#endif /* defined(__TheAbyss__CreatureManager__) */
