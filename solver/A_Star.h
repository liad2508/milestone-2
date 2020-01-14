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
#include "../solution/Route.h"
#include "../solver/Solver.h"
#include "../searchable/graph.h"
#include "../solution/Route.h"

using namespace std;
template<class func>
class A_Star: public Solver<Route*, Graph*> {
private:
    func h;
public:
    A_Star(string sol_type, func met): Solver(sol_type){
        this->h = met;
    }
    Route* solve(Graph* graph) {
        State<myPoint*>* start = graph->getInitialState();
        State<myPoint*>* goal = graph->getInitialState();
        Initiate_A_Star(graph, start, goal);
    }
    void Initiate_A_Star(Graph* graph, State<myPoint*>* start, State<myPoint*>*
            target) {
        // A set of the vertexes
        set<State<myPoint*>*>* vertexesSet = new set<State<myPoint*>*>();
        vertexesSet->insert(start);

        // For node n, cheapScore[n] is the cost of the cheapest path from
        // start to n currently known
        map<State<myPoint*>*, double>* cheapScore = new map<State<myPoint*>*,
                double>();

        // For node n, finalScore[n] := cheapScore[n] + h(n).
        map<State<myPoint*>*, double>* finalScore = new map<State<myPoint*>*,
                double>();
        vector<State<myPoint*>*>* vers = graph->getVertexes();

        // Initialize values to infinity
        Initialize_Map(vers, cheapScore);
        Initialize_Map(vers, finalScore);

        // Initialize start to infinity
        cheapScore->insert({start, start->getCost()});

        // While the set is not empty
        while (vertexesSet->size() > 0) {

            // Getting the vertex with lowest value in finalScore
            State<myPoint*>* lowestVer = Get_Min_Vertex(finalScore);
            if (lowestVer->equals(target)) {
                return;
            }

            // Remove current vertex from set
            vertexesSet->erase(lowestVer);

            // Iterate neighbors
            list<State<myPoint*>*>* neighbors =
                    graph->getAllPossibleStates(lowestVer);
            auto last_neig = neighbors->end();
            for(auto neig = neighbors->begin(); neig != last_neig; neig++) {
                double distance = cheapScore->at(lowestVer) +
                        (*neig)->getCost();

                // If we found a better route
                if (distance < cheapScore->at(*neig)) {
                    (*neig)->setCameFrom(lowestVer);
                    cheapScore->insert({(*neig), distance});
                    finalScore->insert({(*neig), distance + h((*neig))});
                    if (vertexesSet->find((*neig)) == vertexesSet->end()) {
                        vertexesSet->insert((*neig));
                    }
                }
            }
        }

        // We can't reach the target - there is no route to it.
        throw "Was unable to find route with A*";
    }
    void Initialize_Map(vector<State<myPoint*>*>* vertexes, map<State<myPoint*>*,
            double>* the_map) {
        auto last_ver = vertexes->end();
        double f = INFINITY;
        for(auto ver = vertexes->begin(); ver != last_ver; ver++) {
            the_map->insert({(*ver), f});
        }
    }
    State<myPoint*>* Get_Min_Vertex(map<State<myPoint*>*,double>* the_map) {
        double min = INFINITY;
        State<myPoint*>* min_ver = nullptr;
        auto last_ver = the_map->end();
        for (auto ver = the_map->begin(); ver != last_ver; ver++) {
            double val = (*ver).second;
            if (val < min) {
                min_ver = (*ver).first;
                min = val;
            }
        }
        return min_ver;
    }
};

#endif //MILESTONE_2_A_STAR_H
