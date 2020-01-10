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
    int target;
    int goal;
public:
    virtual State<T>* getInitialState();
    virtual State<T>* getGoalState();
    virtual list<State<T>*>* getAllPossibleStates(State<T>* s);
};


#endif //MILESTONE_2_SEARCHABLE_H
