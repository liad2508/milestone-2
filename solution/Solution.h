//
// Created by idan on 10/01/2020.
//

#ifndef MILESTONE_2_SOLUTION_H
#define MILESTONE_2_SOLUTION_H

#include <iostream>
using namespace std;
template <class sol>
class Solution {
private:
    sol solution;
public:
    Solution(){}
    Solution(sol s) {this->solution = s; }
    void setSolution(sol solu) {this->solution = solu;}
    sol getSolution() { return this->solution; }
    string getRepresentation() { return this->representation;}
    virtual string toString() = 0;
    virtual void toFile(ofstream* file) = 0;
    virtual void fromFile(ifstream* file) = 0;
    ~Solution(){}
};


#endif //MILESTONE_2_SOLUTION_H
