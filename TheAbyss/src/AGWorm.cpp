//
//  AGWorm.cpp
//  TheAbyss
//
//  Created by Tiago Ângelo on 10/3/15.
//
//

#include "AGWorm.h"


AGWorm::AGWorm(){
    creatureAuthor = "Andreas Gysin";
    creatureName = "El Worm";
    creatureVersion = "Alpha";
//    setDate(2011, 6, 10); //Y,M,D
    frameCount = 0;
    
    int num = randInt(7, 22); // (7, 22)
    float len = randFloat(2, 15);
    float damp = randFloat(0.85, 0.95);
    float k = randFloat(0.15, 0.3);
    radius = randFloat(1.5, 2.5);
    rSpeed = randFloat(50.f, 150.f);
    rDamp = randFloat(0.005, 0.02);
    nervosismo = randFloat(0.01, 0.3);
    freq1 = randFloat(0.05, 0.2);
    freq2 = randFloat(0.08, 1.1);
    
    nodes = *new vector<Node>();
    
    springs = *new vector<Spring>();
    for (int i = 0; i<num; i++){
        Vec3f p = pos + Vec3f(randFloat(-1, 1), randFloat(-1, 1), randFloat(-1, 1));
        Node n = *new Node(p, damp);
        nodes.push_back(n);
    }
    
    for(int i = 0; i<num-1; i++){
        Spring s = *new Spring(nodes.at(i), nodes.at(i+1), len, k );
        springs.push_back(s);
    }
    
    dest = *new Vec3f();
}

void AGWorm::move(){
    if(randFloat(1.f) < nervosismo){
        dest += *new Vec3f(randFloat(-rSpeed,rSpeed),randFloat(-rSpeed,rSpeed),randFloat(-rSpeed,rSpeed));
    }
    pos.x += (dest.x - pos.x) * rDamp;
    pos.y += (dest.y - pos.y) * rDamp;
    pos.z += (dest.z - pos.z) * rDamp;
    nodes.at(0).setPos(pos);

    //for (vector<Spring*> s)

    for(int i = 0; i < springs.size(); i++) {
        Spring s = springs.at(i);
        s.step();
    }
    for(int i = 0; i < nodes.size(); i++) {
        Node n = nodes.at(i);
        n.step();
    }
    // This call was not part of the original Processing/AGWorm
    rotate(nodes.begin(), nodes.end()-1, nodes.end());

}

void AGWorm::draw(){
    //noFill();
    gl::color(1.f, 1.f, 1.f);
    gl::lineWidth(1.f);
    gl::begin(GL_LINE);
    for(int i = 0; i < springs.size(); i++){
        Spring s = springs.at(i);
        gl::vertex(s.a);
//        app::console() << "s.a["<<i<<"]: " << s.a << endl;
        gl::vertex(s.b);
//        app::console() << "s.b["<<i<<"]: " << s.b << endl;

    }
    gl::end();
    gl::pushMatrices();

    int i = 0;
//    noStroke();
//    sphereDetail(3);
//    fill(255);
    float baseFreq = frameCount * freq1;
    for (int j = 0; j < nodes.size(); j++){
        Node n = nodes.at(j);
        //app::console() << "n[" << j << "]: " << n << endl;
        float d = lmap( sin(baseFreq - i*freq2), -1.f, 1.f, radius, radius * 2);
        gl::pushMatrices();
        gl::translate(n);
        gl::drawSphere(Vec3f::zero(), d);
        gl::popMatrices();
        i++;
    }
    frameCount++;
}