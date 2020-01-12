//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_VERTEX_H
#define MILESTONE_2_VERTEX_H

#include <iostream>
#include <string>
#include <cstring>
#include "State.h"

class Vertex: public State<string*> {
public:
    Vertex(string* st, double c):State(st,c){}
    int equals(State<string*>* target) {
        return strcmp(this->getState()->c_str(),target->getState()->c_str());
    }
};


#endif //MILESTONE_2_VERTEX_H
