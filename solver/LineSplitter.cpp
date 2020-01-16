//
// Created by idan on 11/01/2020.
//

#include "LineSplitter.h"

vector<string*>* LineSplitter::solve(string* problem) {
    vector<string*>* splitted = new vector<string*>;
    auto end_problem = problem->end();
    stringstream final;
    stringstream curr_c;
    bool deldel = false;
    auto delEnd = this->delimeter->end();

    for(auto c = problem->begin(); c != end_problem; c++) {
        curr_c.str("");
        curr_c << *c;
        string s = curr_c.str();
        for (auto del = this->delimeter->begin(); del != delEnd; del++) {
            if (*del == s) {
                deldel = true;
                break;
            }
        }
        if (!deldel) {
            final << *c;
        } else {
            splitted->push_back(new string(final.str()));
            final.str("");
            deldel = false;
        }
    }

    if (!deldel){
        splitted->push_back(new string(final.str()));
    }
    return splitted;
}