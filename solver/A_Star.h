//
// Created by idan on 11/01/2020.
//

#ifndef MILESTONE_2_A_STAR_H
#define MILESTONE_2_A_STAR_H

#include <iostream>
#include <set>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include "../searchable/Route.h"
#include "../solver/Solver.h"
#include "../searchable/graph.h"
#include "../searchable/Route.h"
using namespace std;

class A_Star: public Solver<Route*, Graph*> {
public:
    A_Star(string sol_type): Solver(sol_type){}
    Route* solve(Graph* graph);
    template <class func>
    void Initiate_A_Start(Graph* graph, State<string>* start, State<string>*
            target, func h);
    void Initialize_Map(vector<State<string>*>* vertexes, map<State<string>*,
            double>* the_map);
    State<string>* Get_Min_Vertex(map<State<string>*,double>* the_map);
};


#endif //MILESTONE_2_A_STAR_H
