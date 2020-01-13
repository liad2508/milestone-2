//
// Created by liad on 13/01/2020.
//

#ifndef MILESTONE_2_ROUTE1_H
#define MILESTONE_2_ROUTE1_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <map>
#include "../searchable/State.h"
#include "../searchable/Point.h"
#include "Solution.h"

using namespace std;
class Route {
private:
    list<State<Point*>*>* route;
public:
    Route() {
        this->route = new list<State<Point*>*>;
    }
    list<State<Point*>*>* getRoute() {
        return this->route;
    }
    void addToRoute(State<Point*>* ver) {
        this->route->push_front(ver);
    }
};

#endif //MILESTONE_2_ROUTE1_H
