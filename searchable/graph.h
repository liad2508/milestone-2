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
    vector<Vertex*>* vertexes;
    map<Vertex*,list<Vertex*>*>* edges;
public:
    Graph() {
        this->vertexes = new vector<Vertex*>();
        this->edges = new map<Vertex*,list<Vertex*>*>;
        this->goal = -1;
        this->target = -1;
    };

    // Get target.
    Vertex* getInitialState();

    // Get starting point.
    Vertex* getGoalState();

    // Get all vertex
    vector<Vertex*>* getVertexes() { return this->vertexes; }

    // Returns neighbors
    list<Vertex*>* getAllPossibleStates(Vertex* vertex) {
        return this->edges->at(vertex);
    }
};


#endif //MILESTONE_2_GRAPH_H
