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
#include <list>

#include "TACreatureExample.h"
//#include "SuperCreature.h"

using namespace ci;

class CreatureManager{
public:
    CreatureManager();
    void update();
    void draw();
    void addCreature();
    void removeCreature();

    std::list<TACreatureExample> mCreatures;
};

#endif /* defined(__TheAbyss__CreatureManager__) */
