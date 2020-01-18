//
// Created by idan on 10/01/2020.
//

#include "Route.h"
Route* Route::fromFile(ifstream *file) {
    int size = 0;
    // Deilimeters
    vector<string> *dels = new vector<string>();
    dels->push_back("(");
    dels->push_back(" ");
    dels->push_back(",");
    dels->push_back(")");

    // Splitter for the line in the file
    LineSplitter* splitter = new LineSplitter("LineSplitter", dels);
    string line;
    vector<string *> *splittedRoute;

    std::getline(*file, line);
    splittedRoute = splitter->solve(&line);
    size = splittedRoute->size();

    // Iterating in jumps of 3 like in the toFile format
    for (int i = 0; i < size; i += 3) {
        int x = stoi(*splittedRoute->at(i));
        int y = stoi(*splittedRoute->at(i + 1));
        double cost = stoi(*splittedRoute->at(i + 2));
        myPoint *p = new myPoint(x, y);
        Vertex *v = new Vertex(p, cost);
        this->route->push_back(v);
    }
    return this;
}

void Route::toFile(ofstream *file) {
    auto endOfRoute = this->route->end();
    if (this->route->size() > 0) {
        // Putting data in the file in the following format:
        // (x_1, y_1), cost_1, (x_2, y_2), cost_2, ..., (x_n, y_n), cost_n,
        for (auto start = this->route->begin(); start != endOfRoute; start++) {
            *file << (*start)->toString() << ", ";
        }
        *file << endl;
    }
}

string Route::toString() {
    stringstream route;
    myPoint* p1;
    myPoint* p2;
    auto end = this->route->end();
    auto start = this->route->begin();
    double weight = (*start)->getCost();
    map<string, string*>* directions = new map<string, string*>();
    directions->insert({"(1, 0)", new string("down")});
    directions->insert({"(-1, 0)", new string("up")});
    directions->insert({"(0, 1)", new string("right")});
    directions->insert({"(0, -1)", new string("left")});

    while(start != end) {

        // Get the 2 mypoints
        p1 = (*start)->getState();
        start++;
        if (start != end) {
            p2 = (*start)->getState();

            // Get one of the following: (1,0) (-1,0) (0,1) (0,-1)
            myPoint *p = *p2 - p1;

            // Add more value to weight
            weight += (*start)->getCost();
            // Appending to route
            route << *directions->at(string(p->toStr())) << " (" << weight
                  << "), ";
        }
    }
    string final = route.str();
    final = final.substr(0, (final.size() - 2));
    return final;
}