//
// Created by idan on 09/01/2020.
//

#include "StringReverser.h"

string StringReverser::solve(string problem) {

    string st = problem;
    reverse(st.begin(), st.end());
    return st;
}
