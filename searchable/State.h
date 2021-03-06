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
    string visitOrNot;
    T state;
    double costOfWay;
    double cost;
    State<T>* cameFrom;
public:
    virtual string toString() = 0;
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
    void setCostOfWay(double c) {
        this->costOfWay = c;
    }
    double getCostOfWay () {
        return this->costOfWay;
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
    void setVisit (string v) {
        this->visitOrNot = v;
    }
    string getVisit () {
        return this->visitOrNot;
    }
    virtual bool equals(State<T>* target) = 0;
    virtual bool operator> (State<T> *  state1) = 0;
    ~State(){}
};


#endif //MILESTONE_2_STATE_H