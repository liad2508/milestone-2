//
// Created by idan on 10/01/2020.
//

#include "DFS.h"

Route* DFS::solve(Graph* graph) {
    // Get random starting point
    State<string>* startingVertex = graph->getInitialState();
    startingVertex->setRouteWeight(startingVertex->getCost());

    // Get random ending point
    State<string>* endingVertex = graph->getGoalState();
    endingVertex->setState("target");
    Route* final_route = new Route();
    DFS_Visit(graph, startingVertex, endingVertex);

    // Find the route.
    startingVertex->setState("starting point");
    State<string>* vertex_in_route = endingVertex;

    while(vertex_in_route->getState() != "starting point") {
        final_route->addToRoute(vertex_in_route);
        vertex_in_route = (Vertex*)vertex_in_route->getCameFrom();
    }

    return final_route;
}

void DFS::DFS_Visit(Graph* graph, State<string> *start, State<string> *target) {
    start->setState("visited");
    list<State<string>*>* neighbors = graph->getAllPossibleStates(start);
    auto last_neig = neighbors->end();
    for(auto neig = neighbors->begin(); neig != last_neig; neig++) {

        // We already visited the vertex so we check if there is a better route
        if((*neig)->getState() == "visited") {
            changeRouteWeight(graph, *neig, start);
        }

        // We reached the target - we check whether there was a better route
        else if ((*neig)->equals(target) == 0) {
            changeRouteWeight(graph, *neig, start);
        }

        // We didn't visit the vertex
        else {
            DFS_Visit(graph, *neig, target);
            (*neig)->setState("visited");
        }
    }
}

void DFS::changeRouteWeight(Graph* graph, State<string>* v, State<string>* u) {
    double possible_weight = graph->getEdgeWeight(v,u) + u->getRouteWeight();
    if (v->getRouteWeight() > possible_weight) {
        v->setRouteWeight(possible_weight);
        v->setCameFrom(u);
    }
}