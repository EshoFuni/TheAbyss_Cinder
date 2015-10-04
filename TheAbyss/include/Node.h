//
//  Node.h
//  TheAbyss
//
//  Class used by AGWorm
//
//  Created by Tiago Ângelo on 10/3/15.
//  SEE ALSO:
//  http://stackoverflow.com/questions/180601/using-super-in-c
//

#ifndef __TheAbyss__Node__
#define __TheAbyss__Node__

using namespace ci;

class Node : public Vec3f {
public:
    typedef Vec3f super;
    Node(); // default constructor ?????
    Node(Vec3f v, float damp); // constructor
    
    // METHOD DECLARATION
    void step();
    void applyForce(Vec3f f);
    void setPos(Vec3f p);
    
    // VARIABLE DECLARATION
    float damp;
    Vec3f vel;
    
};


#endif /* defined(__TheAbyss__Node__) */
