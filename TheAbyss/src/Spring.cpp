//
//  Spring.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 10/3/15.
//
//

#include "Spring.h"

Spring::Spring(){}

Spring::Spring(Node a, Node b, float len, float scaler){
    this->a = a;
    this->b = b;
    this->len = len;
    this->scaler = scaler;
}

void Spring::step(){
    Vec3f v = b - a; // PVector.sub(b, a)
    // float m = (v.mag() - len) / 2 * scaler;
    float m = (v.lengthSquared() - len) / 2 * scaler;
    // NOTE: vector.mag = sqrt( v.x * v.x + v.y * v.y + v.z * v.z )
    v.normalize();
    
    v *= m;
    a.applyForce(v);
    
    v *= -1.f;
    b.applyForce(v);
}