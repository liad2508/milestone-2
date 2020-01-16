//
// Created by liad on 14/01/2020.
//

#include "BestFirstSearch.h"

Route * BestFirstSearch::solve(Graph *graph) {


    // Get random starting mypoint
    State<myPoint*> *startingVertex = graph->getInitialState();

// Get random ending mypoint
    State<myPoint*> *endingVertex = graph->getGoalState();
    graph->InitializeVisit();
    BestFirstSearch_visit(graph,startingVertex,endingVertex);

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

void BestFirstSearch::BestFirstSearch_visit(Graph *graph, State<myPoint *> *start, State<myPoint *> *target) {

    list<State<myPoint *> *> open;
    open.push_back(start);
    start->setCostOfWay(start->getCost());
    // maybe initiallizr the parent of start to start
    list<State<myPoint *> *> closed;

    while (!open.empty()) {

        open.sort();
        State<myPoint *> *currentVertex = *open.begin();
        open.pop_front();
        closed.push_back(currentVertex);
        if (currentVertex->equals(target)) {
            break;
        }

        list<State<myPoint *> *> *neighbors = graph->getAllPossibleStates(currentVertex);
        (*neighbors).sort();
        auto last_neig = neighbors->end();
        for (auto neig = neighbors->begin(); neig != last_neig; neig++) {

            if (search(open, *neig) && search(closed, *neig)) {
                (*neig)->setCameFrom(currentVertex);
                double totalPrice = currentVertex->getCostOfWay() + (*neig)->getCost();
                (*neig)->setCostOfWay(totalPrice);
                open.push_back(*neig);
                open.sort();

            }

            if (search(open, *neig) && !search(closed, *neig)) {

                if ((*neig)->getCostOfWay() > currentVertex->getCostOfWay() + (*neig)->getCost()) {

                    (*neig)->setCameFrom(currentVertex);
                    (*neig)->setCostOfWay(currentVertex->getCostOfWay() + (*neig)->getCost());
                    open.sort();

                }
            }
        }
    }
}


bool BestFirstSearch::search(list<State<myPoint *> *> listToSearch, State<myPoint *> *vertex) {

    auto last_vertex = listToSearch.end();
    for (auto it = listToSearch.begin(); it != last_vertex; it++) {

        if (vertex->equals(*it)) {
            return true;
        }

    }
    return false;


}






/*
// Using lambda to compare elements.
auto cmp = [](State<myPoint *> *u, State<myPoint *> *v) { return (u->getCost()) <= (v->getCost()); };
std::priority_queue<State<myPoint *> *, std::vector<State<myPoint *> *>, decltype(cmp)> queue(cmp);
queue.push(start);
while (!queue.empty()) {

State<myPoint *> *firstVertex = queue.top();
queue.pop();
if (firstVertex->equals(target)) {
// maybe need set who came
break;
} else {

list<State<myPoint *> *> *neighbors = graph->getAllPossibleStates(firstVertex);
auto last_neig = neighbors->end();
for (auto neig = neighbors->begin(); neig != last_neig; neig++) {

if ((*neig)->getVisit() != string("visited")) {
(*neig)->setVisit("visited");
queue.push(*neig);
}

}


}

}*/

/*
     // Using lambda to compare elements.
    auto cmp = [](State<myPoint *> *u, State<myPoint *> *v) { return (u->getCost()) <= (v->getCost()); };
    std::priority_queue<State<myPoint *> *, std::vector<State<myPoint *> *>, decltype(cmp)> open(cmp);

    list<State<myPoint*>*> closed;


    open.push(start);
    while (!open.empty()) {

        State<myPoint *> *firstVertex = open.top();
        closed.push_back(firstVertex);
        open.pop();
        if (firstVertex->equals(target)) {
            // maybe need set who came
            break;
        }


        list<State<myPoint *> *> *neighbors = graph->getAllPossibleStates(firstVertex);
        auto last_neig = neighbors->end();
        auto cmp = [](State<myPoint *> *u, State<myPoint *> *v) { return (u->getCost()) <= (v->getCost()); };
        std::priority_queue<State<myPoint *> *, std::vector<State<myPoint *> *>, decltype(cmp)> tempOpen(cmp);


        for (auto neig = neighbors->begin(); neig != last_neig; neig++) {

            if (search_queue(open,*neig) && find_close(closed,*neig)) {
                (*neig)->setCameFrom(firstVertex);
                open.push(*neig);

                }

            }

    }
}

template<typename T> bool search_queue(T& q, State<myPoint *> * s) {
    auto it = q.top();
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

bool find_close(list<State<myPoint*>*> list, State<myPoint*>* s) {

    auto last = list.end();
    for (auto state = list.begin(); state != last; state++) {

        if (s->equals(*state)) {
            return true;
        }
    }
    return false;
}
 */