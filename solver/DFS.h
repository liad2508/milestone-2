//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_DFS_H
#define MILESTONE_2_DFS_H


#include "Solver.h"
#include "../searchable/graph.h"
#include "../solution/Route.h"
#include "../searchable/Vertex.h"

class DFS: public Solver<Route*, Graph*> {
public:
    DFS(string sol_type): Solver(sol_type){}
    Route* solve(Graph* graph);
    void DFS_Visit(Graph* graph, State<myPoint*>* start, State<myPoint*>* target);
    void changeRouteWeight(Graph* graph, State<myPoint*>* v, State<myPoint*>*
            u);

    void InitializeVisit(Graph *graph);
};


#endif //MILESTONE_2_DFS_H
