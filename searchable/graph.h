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
#include "myPoint.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
using namespace std;

class Graph : public Searchable<State<myPoint*>*> {
private:
    vector<State<myPoint*>*>* vertexes;
    map<State<myPoint*>*,list<State<myPoint*>*>*>* neighbors;
    stringstream matrix;

public:
    Graph() {
        this->vertexes = new vector<State<myPoint*>*>();
        this->neighbors = new map<State<myPoint*>*,list<State<myPoint*>*>*>;

    };

    // Get all vertex
    vector<State<myPoint*>*>* getVertexes() { return this->vertexes; }

    // Initialize graph
    void InitializeGraph(string matrix_file);

    void InitializeNeighbors(vector<vector<State<myPoint*>*>*>* create_neig);
    // Returns neighbors
    list<State<myPoint*>*>* getAllPossibleStates(State<myPoint*>* vertex) {
        return this->neighbors->at(vertex);
    }

    void InitializeVisit(Graph *graph);

    void InitializeVisit();

    State<myPoint *> * getVer(int n, int m);

    ~Graph(){
        delete vertexes;
        delete neighbors;
    }
};


#endif //MILESTONE_2_GRAPH1_H
