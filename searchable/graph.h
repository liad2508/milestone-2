//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_GRAPH_H
#define MILESTONE_2_GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stdlib.h>
#include <map>
#include "State.h"
#include "Searchable.h"
#include "../solver/LineSplitter.h"
#include "Vertex.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
using namespace std;

class Graph:public Searchable<string*> {
private:
    vector<State<string*>*>* vertexes;
    map<State<string*>*,list<State<string*>*>*>* edges;
    map<State<string*>*, map<State<string*>*, double>*>* weights;
    stringstream matrix;
    State<string*>* initialState;
    State<string*>* goalState;
public:
    Graph() {
        this->vertexes = new vector<State<string*>*>();
        this->edges = new map<State<string*>*,list<State<string*>*>*>;
        this->weights = new map<State<string*>*, map<State<string*>*, double>*>;
        this->goal = -1;
        this->target = -1;
    };

    // Get target.
    State<string*>* getInitialState() {return this->initialState;}

    // Get starting point.
    State<string*>* getGoalState() {return this->goalState;}

    // Get all vertex
    vector<State<string*>*>* getVertexes() { return this->vertexes; }

    // Get weight
    double getEdgeWeight(State<string*>* v, State<string*>* u) {
        return weights->at(v)->at(u);
    }

    // Initialize graph
    void InitializeGraph(string matrix_file);

    int InitializeVertexes(vector<string*>* vers);

    // Returns neighbors
    list<State<string*>*>* getAllPossibleStates(State<string*>* vertex) {
        return this->edges->at(vertex);
    }
};


#endif //MILESTONE_2_GRAPH_H
