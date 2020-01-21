
// Created by liad on 12/01/2020.
//

#include "BFS.h"

Route* BFS::solve(Graph *graph) {
    graph->InitializeVisit();
    //need initialize all the distance to infinity
    BFS_Visit(graph, graph->getInitialState(), graph->getGoalState());

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
            State<myPoint*>* v = (*neig);
            // We reached the target
            if ((*neig)->equals(target)) {
                (*neig)->setCameFrom(firstVertex);
                return;
            }
            if ((*neig)->getVisit() != string("visited")) {
                (*neig)->setVisit("visited");
                (*neig)->setCameFrom(firstVertex);
                queue.push_back(*neig);
            }
            this->num++;
        }
    }

}

BFS * BFS::clone() {
    return new BFS(this->solution_type);
}