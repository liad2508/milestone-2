//
// Created by liad on 13/01/2020.
//

#ifndef MILESTONE_2_MYPOINT_H
#define MILESTONE_2_MYPOINT_H

#include <iostream>
#include <sstream>

using namespace std;

class myPoint {

private:
    int x;
    int y;

public:
    myPoint(int i, int j) {
        this->x = i;
        this->y = j;
    }

    int getX() {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY()  {
        return y;
    }

    void setY(int y) {
       this->y = y;
    }
    string toStr();
    myPoint* operator-(myPoint* p);
    bool equals(myPoint* p);
};


#endif //MILESTONE_2_MYPOINT_H
