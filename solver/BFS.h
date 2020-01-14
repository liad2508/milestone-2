//
// Created by liad on 13/01/2020.
//

#ifndef MILESTONE_2_BFS_H
#define MILESTONE_2_BFS_H


#include "Solver.h"
#include "../searchable/Vertex.h"
#include "../searchable/graph.h"
#include "../solution/Route.h"

class BFS: public Solver<Graph*, Route*> {
public:
    BFS(string sol_type): Solver(sol_type){}
    Route* solve(Graph* graph);
    void BFS_Visit(Graph* graph, State<myPoint*>* start, State<myPoint*>*
            target);

};



#endif //MILESTONE_2_BFS_H
