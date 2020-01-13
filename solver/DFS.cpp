//
// Created by idan on 10/01/2020.
//

#include "DFS.h"

Route* DFS::solve(Graph* graph) {
    // Get random starting point
    State<Point*>* startingVertex = graph->getInitialState();

    // Get random ending point
    State<Point*>* endingVertex = graph->getGoalState();
    Route* final_route = new Route();
    graph->InitializeVisit();
    DFS_Visit(graph, startingVertex, endingVertex);

    // Find the route.
    State<Point*>* vertex_in_route = endingVertex;

    while(!vertex_in_route->equals(startingVertex)) {
        final_route->addToRoute(vertex_in_route);
        vertex_in_route = (Vertex*)vertex_in_route->getCameFrom();
    }
    final_route->addToRoute(startingVertex);
    return final_route;
}

void DFS::DFS_Visit(Graph* graph, State<Point*> *start, State<Point*> *target) {
    list<State<Point*>*>* neighbors = graph->getAllPossibleStates(start);
    auto last_neig = neighbors->end();
    for(auto neig = neighbors->begin(); neig != last_neig; neig++) {

        // We already visited the vertex so we check if there is a better route
        if((*neig)->getVisit() == string("visited")) {
            continue;
        }

        // We reached the target
        else if ((*neig)->equals(target) == 0) {
            ((*neig)->setCameFrom(start));
            break;
        }

        // We didn't visit the vertex
        else {
            ((*neig)->setCameFrom(start));
            DFS_Visit(graph, *neig, target);
            (*neig)->setVisit("visited");
        }
    }
}

