//
// Created by idan on 09/01/2020.
//

#ifndef MILESTONE_2_STRINGREVERSER_H
#define MILESTONE_2_STRINGREVERSER_H


#include "Solver.h"
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;



class StringReverser: public Solver<string,string> {
public:
    StringReverser(string sol_type):Solver(sol_type){}
    string solve(string s);
};


#endif //MILESTONE_2_STRINGREVERSER_H
