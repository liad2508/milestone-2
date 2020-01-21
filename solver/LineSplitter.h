//
// Created by idan on 11/01/2020.
//

#ifndef MILESTONE_2_LINESPLITTER_H
#define MILESTONE_2_LINESPLITTER_H
#include "Solver.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

class LineSplitter: public Solver<string*, vector<string*>*>{
private:
    vector<string>* delimeter;
public:
    LineSplitter(string sol_type, vector<string>* del): Solver(sol_type) {
        this->delimeter = del;
    }
    vector<string*>* solve(string* problem);
    LineSplitter* clone();
};


#endif //MILESTONE_2_LINESPLITTER_H
