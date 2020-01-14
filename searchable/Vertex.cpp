//
// Created by idan on 10/01/2020.
//

#include "Vertex.h"
string Vertex::toString() {
    stringstream repr;
    myPoint* p = this->getState();
    repr << p->toStr() << ", " << this->getCost();
    return repr.str();
}