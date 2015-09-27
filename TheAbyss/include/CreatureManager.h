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

using namespace ci;

class CreatureManager{
public:
    CreatureManager();
    void update();
    void draw();

    void addRandomCreature();
    void removeLastCreature();
    
    std::vector<SuperCreature*> mCreatures; // creature container
    std::list<string> mClasses; //list of all creature classes
    

private:
    
};

#endif /* defined(__TheAbyss__CreatureManager__) */
