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


class BestFirstSearch: public Solver<Route*, Graph*> {

public:
    BestFirstSearch(string sol_type): Solver(sol_type){}
    Route* solve(Graph* graph);
    void BestFirstSearch_visit(Graph* graph, State<myPoint*>* start, State<myPoint*>* target);
    bool search(list<State<myPoint*>*> listToSearch, State<myPoint*>* vertex);



};


#endif //MILESTONE_2_BESTFIRSTSEARCH_H
