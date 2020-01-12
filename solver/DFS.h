//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_DFS_H
#define MILESTONE_2_DFS_H


#include "Solver.h"
#include "../searchable/graph.h"
#include "../searchable/Route.h"
#include "../searchable/Vertex.h"

class DFS: public Solver<Route*, Graph*> {
public:
    DFS(string sol_type): Solver(sol_type){}
    Route* solve(Graph* graph);
    void DFS_Visit(Graph* graph, State<string>* start, State<string>* target);
    void changeRouteWeight(Graph* graph, State<string>* v, State<string>* u);
};


#endif //MILESTONE_2_DFS_H
