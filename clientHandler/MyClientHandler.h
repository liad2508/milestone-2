//
// Created by idan on 14/01/2020.
//

#ifndef MILESTONE_2_MYCLIENTHANDLER_H
#define MILESTONE_2_MYCLIENTHANDLER_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "../clientHandler/ClientHandler.h"
#include "../solution/Route.h"
#include "../searchable/graph.h"

using namespace std;
class MyClientHandler : public ClientHandler<Graph*, Route*, Route*> {

    ofstream f;
    string* nameOfFile;
    stringstream data;
    int num = 0;

public:
    MyClientHandler (Solver<Graph*, Route*>* so, CacheManager<Route*>* cache)
    : ClientHandler(so, cache){}
    MyClientHandler* setNameOfFile(string *nameOfFile);

    void handleClient (ostringstream* InputStream, ostringstream*
    OutputStream);

    MyClientHandler *clone();
};


#endif //MILESTONE_2_MYCLIENTHANDLER_H
