//
//  AGCubus.h
//  TheAbyss
//
//  Created by Tiago Ângelo on 7/23/15.
//
//

#ifndef __TheAbyss__AGCubus__
#define __TheAbyss__AGCubus__

#pragma once

#include "SuperCreature.h"


class AGCubus: public SuperCreature{
public:
    AGCubus();
    void move();
    void update();
};

#endif /* defined(__TheAbyss__AGCubus__) */
