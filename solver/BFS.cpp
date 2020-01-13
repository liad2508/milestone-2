
// Created by liad on 12/01/2020.
//

#include "BFS.h"

Route* BFS::solve(Graph *graph) {

    //need initialize all the distance to infinity

// Get random starting point
    State<Point*> *startingVertex = graph->getInitialState();

// Get random ending point
    State<Point*> *endingVertex = graph->getGoalState();
    graph->InitializeVisit();
    BFS_Visit(graph, startingVertex, endingVertex);
    Route* final_route = new Route();

    // Find the route.
    State<Point*>* vertex_in_route = endingVertex;

    while(!vertex_in_route->equals(startingVertex)) {
        final_route->addToRoute(vertex_in_route);
        vertex_in_route = (Vertex*)vertex_in_route->getCameFrom();
    }
    final_route->addToRoute(startingVertex);
    return final_route;

}

void BFS::BFS_Visit(Graph *graph, State<Point *> *start, State<Point *> *target) {

    list<State<Point*>*> queue;
    start->setVisit("visited");
    queue.push_back(start);
    while (!queue.empty()) {

        _List_iterator<State<Point *> *> iter = queue.begin();
        State<Point*>* firstVertex = *iter;
        queue.pop_front();

        list<State<Point*>*>* neighbors = graph->getAllPossibleStates(firstVertex);
        auto last_neig = neighbors->end();
        for(auto neig = neighbors->begin(); neig != last_neig; neig++) {

            if ((*neig)->getVisit() != string("visited")) {
                (*neig)->setVisit("visited");
                (*neig)->setCameFrom(firstVertex);
                queue.pop_front();
            }
            // We reached the target 
            if ((*neig)->equals(target)) {
                break;
            }
        }
    }

}