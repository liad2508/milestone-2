//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_SEARCHABLE_H
#define MILESTONE_2_SEARCHABLE_H


#include "State.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>

template <class T>
class Searchable {
protected:
    T initialState;
    T goalState;
public:
    T getInitialState() { return this->initialState; }
    T getGoalState() {return this->goalState;}
    virtual list<T>* getAllPossibleStates(T s) = 0;
    ~Searchable(){}
};


#endif //MILESTONE_2_SEARCHABLE_H
