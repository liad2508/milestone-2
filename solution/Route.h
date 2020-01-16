//
// Created by liad on 13/01/2020.
//

#ifndef MILESTONE_2_ROUTE1_H
#define MILESTONE_2_ROUTE1_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stdlib.h>
#include <map>
#include "../solver/LineSplitter.h"
#include "../searchable/Point.h"
#include "../searchable/State.h"
#include "../searchable/Vertex.h"
#include "../solution/Solution.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
using namespace std;

class Route: public Solution <State<myPoint*>*>{
private:
    list<State<myPoint*>*>* route;
public:
    Route() :Solution(){}
    void addToRoute(State<myPoint*>* ver) {
        this->route->push_front(ver);
    }
    string toString();
    void toFile(ofstream* file);
    void fromFile(ifstream* file);
};

#endif //MILESTONE_2_ROUTE1_H