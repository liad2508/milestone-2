//
// Created by idan on 10/01/2020.
//

#include "DFS.h"

Route* DFS::solve(Graph* graph) {
    // Get random starting mypoint
    State<myPoint*>* startingVertex = graph->getInitialState();

    // Get random ending mypoint
    State<myPoint*>* endingVertex = graph->getGoalState();
    graph->InitializeVisit();
    DFS_Visit(graph, startingVertex, endingVertex);

    Route* final_route = new Route();
    State<myPoint*>* end =  graph->getGoalState();
    State<myPoint*>* start =  graph->getInitialState();
    while(!end->equals(start)) {
        final_route->addToRoute(end);
        end = end->getCameFrom();
    }
    final_route->addToRoute(start);
    return final_route;
}

void DFS::DFS_Visit(Graph* graph, State<myPoint*> *start, State<myPoint*>
        *target) {
    list<State<myPoint*>*>* neighbors = graph->getAllPossibleStates(start);
    auto last_neig = neighbors->end();
    for(auto neig = neighbors->begin(); neig != last_neig; neig++) {

        // We already visited the vertex so we check if there is a better route
        if((*neig)->getVisit() == string("visited")) {
            this->num++;
            continue;
        }

        // We reached the target
        else if ((*neig)->equals(target)) {
            ((*neig)->setCameFrom(start));
            this->num++;
            break;
        }

        // We didn't visit the vertex
        else {
            ((*neig)->setCameFrom(start));
            (*neig)->setVisit("visited");
            DFS_Visit(graph, *neig, target);
        }
        this->num++;
    }
}

DFS * DFS::clone() {
    return new DFS(this->solution_type);
}
