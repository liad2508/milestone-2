//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_VERTEX_H
#define MILESTONE_2_VERTEX_H

#include <iostream>
#include <string>
#include <cstring>
#include "State.h"
#include "Point.h"

class Vertex: public State<Point*> {
public:
    Vertex(Point* st, double c):State(st,c){}
    int equals(State<Point*>* target) {
        return (this->getState()->getX() == target->getState()->getX() && this->getState()->getY() == target->getState()->getY());
    }
};


#endif //MILESTONE_2_VERTEX_H
