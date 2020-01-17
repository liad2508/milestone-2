//
// Created by liad on 14/01/2020.
//

#ifndef MILESTONE_2_BESTFIRSTSEARCH_H
#define MILESTONE_2_BESTFIRSTSEARCH_H


#include "Solver.h"
#include "../searchable/Vertex.h"
#include "../searchable/graph.h"
#include "../solution/Route.h"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "Solver.h"
#include "../searchable/Vertex.h"
#include "../searchable/graph.h"
#include "../solution/Route.h"


class BestFirstSearch: public Solver<Graph*,Route*> {

public:
    BestFirstSearch(string sol_type): Solver(sol_type){}
    Route* solve(Graph* graph);
    void BestFirstSearch_visit(Graph* graph, State<myPoint*>* start, State<myPoint*>* target);
    bool search(vector<State<myPoint*>*> listToSearch, State<myPoint*>* vertex);
    void swap(State<myPoint *> * xp, State<myPoint *> * yp);
    void bubbleSort(vector<State<myPoint *> *>* open);
    vector<State<myPoint *> *>* bubbleSortList(list<State<myPoint *> *> *list);

    State<myPoint *> *getMinNeig(list<State<myPoint *> *> *neigs);
};


#endif //MILESTONE_2_BESTFIRSTSEARCH_H
