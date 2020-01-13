//
// Created by liad on 13/01/2020.
//

#ifndef MILESTONE_2_GRAPH1_H
#define MILESTONE_2_GRAPH1_H


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
#include "Point.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
using namespace std;

class Graph:public Searchable<Point*> {
private:
    vector<State<Point*>*>* vertexes;
    map<State<Point*>*,list<State<Point*>*>*>* neighbors;
    stringstream matrix;
    State<Point*>* initialState;
    State<Point*>* goalState;
public:
    Graph() {
        this->vertexes = new vector<State<Point*>*>();
        this->neighbors = new map<State<Point*>*,list<State<Point*>*>*>;
        this->goal = -1;
        this->target = -1;
    };

    // Get target.
    State<Point*>* getInitialState() {return this->initialState;}

    // Get starting point.
    State<Point*>* getGoalState() {return this->goalState;}

    // Get all vertex
    vector<State<Point*>*>* getVertexes() { return this->vertexes; }

    // Initialize graph
    void InitializeGraph(string matrix_file);

    void InitializeNeighbors(vector<vector<State<Point*>*>*>* create_neig);
    // Returns neighbors
    list<State<Point*>*>* getAllPossibleStates(State<Point*>* vertex) {
        return this->neighbors->at(vertex);
    }

    void InitializeVisit(Graph *graph);

    void InitializeVisit();
};


#endif //MILESTONE_2_GRAPH1_H
