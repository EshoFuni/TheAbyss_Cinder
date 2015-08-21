//
//  CreatureManager.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15,
//  added Horácio Tomé-Marques on 7/24/15,
//  and João Menezes from of these days!;–}.
//
//

#ifndef __TheAbyss__CreatureManager__
#define __TheAbyss__CreatureManager__

#pragma once
#include <list>

#include "TACreatureExample.h"
#include "HTMPreGelly.h"
//#include "SuperCreature.h"

using namespace ci;

class CreatureManager{
public:
    CreatureManager();
    void update();
    void draw();
    void addCreature();
    void removeCreature();

    std::list<TACreatureExample> mCreatures0;
    std::list<HTMPreGelly> mCreatures1;
};

#endif /* defined(__TheAbyss__CreatureManager__) */
