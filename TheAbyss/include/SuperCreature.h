//
//  SuperCreature.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
//
//

#ifndef __TheAbyss__SuperCreature__
#define __TheAbyss__SuperCreature__

#pragma once

using namespace ci;
using namespace std;

class SuperCreature {
public:
    
    
    SuperCreature();
//    ~SuperCreature();
    
//    virtual void move();
//    virtual void draw();
    void applyTransforms();
    
    string creatureName, creatureAuthor, creatureVersion;
    //CreatureDate creatureDate;
    
    //CreatureManager cm;
    
protected:
    Vec3f pos, rot, sca;
private:
    Vec3f projectedPos;
    float energy, power;
};

#endif /* defined(__TheAbyss__SuperCreature__) */
