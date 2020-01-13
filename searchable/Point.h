//
// Created by liad on 13/01/2020.
//

#ifndef MILESTONE_2_POINT_H
#define MILESTONE_2_POINT_H

using namespace std;

class Point {

private:
    int x;
    int y;

public:
    Point(int i, int j) {
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

};


#endif //MILESTONE_2_POINT_H
