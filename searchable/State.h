//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_STATE_H
#define MILESTONE_2_STATE_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
template <class T>
class State {
private:
    T state;
    double cost;
    State<T>* cameFrom;
    double route_weight = 0;
public:
    State(T st, double c) {
        this->state = st;
        this->cost = c;
    };
    void setCost(double co) {
        this->cost = co;
    }
    double getCost() {
        return this->cost;
    }

    void setCameFrom(State<T>* caFrom) {
        this->cameFrom = caFrom;
    }
    State<T>* getCameFrom() {
        return this->cameFrom;
    }

    void setState(T st) {
        this->state = st;
    }
    T getState() {
        return this->state;
    }
    double getRouteWeight() {
        return this->route_weight;
    }
    void setRouteWeight(double weight) {
        this->route_weight = weight;
    }
    virtual int equals(State<T>* target) = 0;
};


#endif //MILESTONE_2_STATE_H
