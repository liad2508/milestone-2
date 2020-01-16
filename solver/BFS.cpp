
// Created by liad on 12/01/2020.
//

#include "BFS.h"

Route* BFS::solve(Graph *graph) {

    //need initialize all the distance to infinity

// Get random starting point
    State<myPoint*> *startingVertex = graph->getInitialState();

// Get random ending point
    State<myPoint*> *endingVertex = graph->getGoalState();
    graph->InitializeVisit();
    BFS_Visit(graph, startingVertex, endingVertex);
    Route* final_route = new Route();

    // Find the route.
    State<myPoint*>* vertex_in_route = endingVertex;

    while(!vertex_in_route->equals(startingVertex)) {
        final_route->addToRoute(vertex_in_route);
        vertex_in_route = (Vertex*)vertex_in_route->getCameFrom();
    }
    final_route->addToRoute(startingVertex);
    return final_route;

}

void BFS::BFS_Visit(Graph *graph, State<myPoint *> *start, State<myPoint *>
        *target) {

    list<State<myPoint*>*> queue;
    start->setVisit("visited");
    queue.push_back(start);
    while (!queue.empty()) {

        _List_iterator<State<myPoint *> *> iter = queue.begin();
        State<myPoint*>* firstVertex = *iter;
        queue.pop_front();

        list<State<myPoint*>*>* neighbors = graph->getAllPossibleStates
                (firstVertex);
        auto last_neig = neighbors->end();
        for(auto neig = neighbors->begin(); neig != last_neig; neig++) {

            if ((*neig)->getVisit() != string("visited")) {
                (*neig)->setVisit("visited");
                (*neig)->setCameFrom(firstVertex);
                queue.push_back(*neig);
            }
            // We reached the target 
            if ((*neig)->equals(target)) {
                break;
            }
            this->num++;
        }
    }

}