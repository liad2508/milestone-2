//
// Created by liad on 13/01/2020.
//

#include "myPoint.h"
string myPoint::toStr() {
    stringstream repr;
    repr << "(" << this->x << ", " << this->y << ")";
    return repr.str();
}

myPoint* myPoint::operator-(myPoint *p) {
    int newX= this->x - p->x;
    int newY= this->y - p->y;
    return new myPoint(newX, newY);
}

bool myPoint::equals(myPoint *p) {
    return (this->x == p->x && this->y == p->y);
}