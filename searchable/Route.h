//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_ROUTE_H
#define MILESTONE_2_ROUTE_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <map>
#include "State.h"

using namespace std;
class Route {
private:
    list<State<string>*>* route;
public:
Route() {
    this->route = new list<State<string>*>;
}
    list<State<string>*>* getRoute() {
    return this->route;
}
void addToRoute(State<string>* ver) {
    this->route->push_front(ver);
}
~Route(){
    delete route;
}
};


#endif //MILESTONE_2_ROUTE_H
