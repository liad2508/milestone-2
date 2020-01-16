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
    int equals(State<myPoint*>* target) {
        return (this->getState()->getX() == target->getState()->getX() && this->getState()->getY() == target->getState()->getY());
    }
    bool operator()(State<myPoint *> *state1, State<myPoint *> *state2) {

        return (state1->getCostOfWay() < state2->getCostOfWay());
    }
    string toString();
};


#endif //MILESTONE_2_VERTEX_H
