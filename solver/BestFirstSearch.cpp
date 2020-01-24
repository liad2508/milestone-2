//
// Created by liad on 14/01/2020.
//

#include "BestFirstSearch.h"

Route * BestFirstSearch::solve(Graph *graph) {

    Route * final_route = new Route();
    // Get random starting mypoint
    if(!(graph->getInitialState()->equals(graph->getGoalState()))) {
        graph->InitializeVisit();
        BestFirstSearch_visit(graph, graph->getInitialState(),
                              graph->getGoalState());

        State<myPoint *> *end = graph->getGoalState();
        State<myPoint *> *start = graph->getInitialState();
        while (!end->equals(start)) {
            final_route->addToRoute(end);
            end = end->getCameFrom();
        }
    }
    final_route->addToRoute(graph->getInitialState());
    final_route->flip();
    return final_route;

}

void BestFirstSearch::BestFirstSearch_visit(Graph *graph, State<myPoint *> *start, State<myPoint *> *target) {

    vector<State<myPoint *> *> open;
    open.push_back(start);
    start->setCostOfWay(start->getCost());
    // maybe initiallizr the parent of start to start
    vector<State<myPoint *> *> closed;
    State<myPoint *> *prev = NULL;

    while (!open.empty()) {
        State<myPoint *> *currentVertex = *open.begin();
        open.erase(open.begin());
        bubbleSort(&open);
        closed.push_back(currentVertex);
        if (currentVertex->equals(target)) {
            prev = getMinNeig(graph->getAllPossibleStates(
                    currentVertex));
            currentVertex->setCameFrom(prev);
            this->num++;
            return;
        }
        list<State<myPoint *> *> *neighbors = graph->getAllPossibleStates(
                currentVertex);
        auto last_neig = neighbors->end();
        for (auto neig = neighbors->begin(); neig != last_neig; neig++) {

            if (!search(open, *neig) && !search(closed, *neig)) {
                (*neig)->setCameFrom(currentVertex);
                double totalPrice =
                        currentVertex->getCostOfWay() + (*neig)->getCost();
                (*neig)->setCostOfWay(totalPrice);
                open.push_back(*neig);
                bubbleSort(&open);
            } else {
                if ((*neig)->getCostOfWay() >
                    (currentVertex->getCostOfWay() + (*neig)->getCost())) {
                    (*neig)->setCameFrom(currentVertex);
                    (*neig)->setCostOfWay(currentVertex->getCostOfWay() +
                                          (*neig)->getCost());
                    open.push_back(*neig);
                    bubbleSort(&open);
                }
            }
            this->num++;
        }
        bubbleSort(&open);
    }
}


bool BestFirstSearch::search(vector<State<myPoint *> *> listToSearch,
        State<myPoint *> *vertex) {

    auto last_vertex = listToSearch.end();
    for (auto it = listToSearch.begin(); it != last_vertex; it++) {

        if (vertex->equals(*it)) {
            return true;
        }

    }
    return false;
}


// A function to implement bubble sort
void BestFirstSearch::bubbleSort(vector<State<myPoint *> *>* open)
{
    int i, j;
    int n = open->size();

    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (*open->at(j) > open->at(j + 1)) {
                State<myPoint *> *tmp = open->at(j);
                open->at(j) = open->at(j + 1);
                open->at(j + 1) = tmp;
            }
        }
    }
}

vector<State<myPoint *> *>* BestFirstSearch::bubbleSortList
(list<State<myPoint *> *> *list) {
    vector<State<myPoint *> *>* v = new vector<State<myPoint *> *>;
    auto end = list->end();
    for(auto start = list->begin(); start != end; start++) {
        v->push_back((*start));
    }
    bubbleSort(v);
    return  v;


}

State<myPoint *> *BestFirstSearch::getMinNeig(list<State<myPoint *> *> *neigs) {
    auto end = neigs->end();
    State<myPoint *> * minVec = (*neigs->begin());
    for(auto start = neigs->begin(); start != end; start++) {
        if(*minVec > (*start)){
            minVec = (*start);
        }
    }
    return minVec;
}


BestFirstSearch * BestFirstSearch::clone() {
    return new BestFirstSearch(this->solution_type);
}