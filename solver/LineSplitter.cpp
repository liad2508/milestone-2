//
// Created by idan on 11/01/2020.
//

#include "LineSplitter.h"
vector<string*>* LineSplitter::solve(string* problem) {
    vector<string*>* splitted = new vector<string*>;
    auto end_problem = problem->end();
    stringstream final;
    for(auto c = problem->begin(); c != end_problem; c++) {
        if (std::find(this->delimeter->begin(), this->delimeter->end(), c)
        == this->delimeter->end()) {
            final << *c;
        } else {
            splitted->push_back(new string(final.str()));
            final.str("");
        }
    }
    return splitted;
}