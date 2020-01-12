//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_SOLVER_H
#define MILESTONE_2_SOLVER_H
#include <iostream>
#include <string.h>
using namespace std;

template <class Problem, class Solution>
class Solver {
protected:
    string solution_type;
public:
    Solver(string sol_type) {this->solution_type = sol_type;}
    virtual Solution solve(Problem problem) = 0;
    string getSolutionType() { return solution_type; }
};




#endif //MILESTONE_2_SOLVER_H
