//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_GRAPH_H
#define MILESTONE_2_GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <map>
#include "State.h"
#include "Searchable.h"
#include "Vertex.h"

class Graph:public Searchable<string> {
private:
    vector<State<string>*>* vertexes;
    map<State<string>*,list<State<string>*>*>* edges;
public:
    Graph() {
        this->vertexes = new vector<State<string>*>();
        this->edges = new map<State<string>*,list<State<string>*>*>;
        this->goal = -1;
        this->target = -1;
    };

    // Get target.
    State<string>* getInitialState();

    // Get starting point.
    State<string>* getGoalState();

    // Get all vertex
    vector<State<string>*>* getVertexes() { return this->vertexes; }

    // Returns neighbors
    list<State<string>*>* getAllPossibleStates(State<string>* vertex) {
        return this->edges->at(vertex);
    }
};


#endif //MILESTONE_2_GRAPH_H
