//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_VERTEX_H
#define MILESTONE_2_VERTEX_H

#include <iostream>
#include <string>
#include <cstring>
#include "State.h"
#include "myPoint.h"

class Vertex: public State<myPoint*> {
public:
    Vertex(myPoint* st, double c):State(st,c){}
    bool equals(State<myPoint*>* target) {
        return this->getState()->equals(target->getState());
    }
    bool operator>(State<myPoint *> *state1) {
        return (this->getCostOfWay()> state1->getCostOfWay());
    }
    string toString();
};


#endif //MILESTONE_2_VERTEX_H