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
#include <vector>
#include "cinder/Rand.h"

#include "TACreatureExample.h"
<<<<<<< HEAD
#include "HTMPreGelly.h"
//#include "SuperCreature.h"
=======
#include "AGCubus.h"
#include "SuperCreature.h"
#include "HTMPreGelly.h"
>>>>>>> Tiago_dev

using namespace ci;

class CreatureManager{
public:
    CreatureManager();
    void update();
    void draw();

<<<<<<< HEAD
    std::list<TACreatureExample> mCreatures0;
    std::list<HTMPreGelly> mCreatures1;
=======
    void addRandomCreature();
    void removeLastCreature();
    
    std::vector<SuperCreature*> mCreatures; // creature container
    std::list<string> mClasses; //list of all creature classes
    

private:
    
>>>>>>> Tiago_dev
};

#endif /* defined(__TheAbyss__CreatureManager__) */
