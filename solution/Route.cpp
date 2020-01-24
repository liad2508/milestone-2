//
// Created by idan on 10/01/2020.
//

#include "Route.h"
Route* Route::fromFile(ifstream *file) {
    m1.lock();
    int size = 0;
    this->route = new vector<State<myPoint*>*>;
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
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    splittedRoute = splitter->solve(&line);
    size = splittedRoute->size();

    // Iterating in jumps of 3 like in the toFile format
    for (int i = 0; i < (size - 1); i += 3) {
        int x = stoi(*splittedRoute->at(i));
        int y = stoi(*splittedRoute->at(i + 1));
        double cost = stoi(*splittedRoute->at(i + 2));
        myPoint *p = new myPoint(x, y);
        Vertex *v = new Vertex(p, cost);
        this->route->push_back(v);
    }
    m1.unlock();
    return this;
}

void Route::toFile(ofstream *file) {
    m2.lock();
    auto endOfRoute = this->route->end();
    if (this->route->size() > 0) {
        // Putting data in the file in the following format:
        // (x_1, y_1), cost_1, (x_2, y_2), cost_2, ..., (x_n, y_n), cost_n,
        for (auto start = this->route->begin(); start != endOfRoute; start++) {
            *file << (*start)->toString() << ", ";
        }
        *file << endl;
    }
    m2.unlock();
}
void Route::flip() {
    vector<State<myPoint*>*>* flipped = new vector<State<myPoint*>*>();
    auto end = this->route->rend();
    for(auto start = this->route->rbegin(); start != end; start++) {
        flipped->push_back(*start);
    }
    this->route = flipped;
}
string Route::toString() {
    m3.lock();
    stringstream route;
    int i = 0;
    int route_size = this->route->size();
    double weight = this->route->at(0)->getCost();
    map<string, string*>* directions = new map<string, string*>();
    directions->insert({"(1, 0)", new string("down")});
    directions->insert({"(-1, 0)", new string("up")});
    directions->insert({"(0, 1)", new string("right")});
    directions->insert({"(0, -1)", new string("left")});

    while(i < route_size) {
        if ((i + 1) != route_size) {
            // Get one of the following: (1,0) (-1,0) (0,1) (0,-1)
            myPoint *p = (*this->route->at(i + 1)->getState()) -
                    this->route->at(i)->getState();

            // Add more value to weight
            weight += this->route->at(i)->getCost();
            // Appending to route
            route << *directions->at(string(p->toStr())) << " (" << weight
                  << "), ";
        }
        i+=2;
    }
    string final = route.str();
    final = final.substr(0, (final.size() - 2));
    m3.unlock();
    return final;
}