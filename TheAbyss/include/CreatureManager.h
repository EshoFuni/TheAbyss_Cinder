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

#include "SuperCreature.h"
#include "AGWorm.h"
#include "LPHubert.h"
#include "TAHubert.h"
#include "OTFather.h"
#include "PXPSonar.h"

using namespace ci;

class CreatureManager{
public:
    CreatureManager();
    void update();
    void draw();
    
    void addRandomCreature();
    void removeLastCreature();
    void compPlus();
    void compMinus();
    void addWorm(); // FOR TESTING ONLY!!!!!!
    void addPXP();
    void addFather();
    void addHubert();
    
    std::vector<SuperCreature*> mCreatures; // creature container
    std::list<string> mClasses; //list of all creature classes
    

private:
    
};

#endif /* defined(__TheAbyss__CreatureManager__) */
