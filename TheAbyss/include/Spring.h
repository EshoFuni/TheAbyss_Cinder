//
//  Spring.h
//  TheAbyss
//
//  Class used by AGWorm
//
//
//  Created by Tiago Ângelo on 10/3/15.
//  SEE ALSO:
//  https://libcinder.org/docs/guides/flocking/chapter2.html

#ifndef __TheAbyss__Spring__
#define __TheAbyss__Spring__

#pragma once

#include "Node.h"

class Spring{
public:
    Spring();
    Spring(Node a, Node b, float len, float scaler); // constructor
    
    // METHOD DECLARATION
    void step();
    // VARIABLE DECLARATION
    float len;
    float scaler;
    Node a, b;
};

#endif /* defined(__TheAbyss__Spring__) */
