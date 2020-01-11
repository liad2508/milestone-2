//
// Created by idan on 10/01/2020.
//

#include "graph.h"
State<string> * Graph::getInitialState() {
    this->goal = rand() % this->vertexes->size();
    while (this->goal == this->target) {
        this->goal = rand() % this->vertexes->size();
    }
    return this->vertexes->at(this->goal);
}

State<string> * Graph::getGoalState() {
    this->target = rand() % this->vertexes->size();
    while (this->target == this->goal) {
        this->target = rand() % this->vertexes->size();
    }
    return this->vertexes->at(this->target);
}

