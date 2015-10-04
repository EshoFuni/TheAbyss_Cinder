//
//  Node.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 10/3/15.
//
//

#include "Node.h"

Node::Node(){ // default constructor ????
}

Node::Node(Vec3f v, float damp){
    //super(v.x, v.y, v.z);
    this->x = v.x;
    this-> y = v.y;
    this-> z = v.z;
    this->damp = damp;
    vel = *new Vec3f();
}

void Node::step(){
    //input += vel; // add(vel); ????????
    
    this-> x += vel.x;
    this-> y += vel.y;
    this-> z += vel.z;
    vel *= damp; // vel.mult(damp) ???????
}

void Node::applyForce(Vec3f f){
    vel += f;
}

void Node::setPos(Vec3f p){
    this-> x = p.x;
    this-> y = p.y;
    this-> z = p.z;
    vel = *new Vec3f();
}

