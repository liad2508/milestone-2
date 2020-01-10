//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_MYTESTCLIENTHANDLER_H
#define MILESTONE_2_MYTESTCLIENTHANDLER_H
#include <string>
#include <sstream>
#include <iostream>
#include "ClientHandler.h"
#include "../solver/Solver.h"
#include "../cache/CacheManager.h"
#include "../solution/Solution.h"

class MyTestClientHandler: public ClientHandler {
    Solver<string, string> *sol;
    CacheManager<Solution<const char*>>* cacheManager;
public:
    MyTestClientHandler (Solver<string, string>* so,
            CacheManager<Solution<const char*>>* cache) {
        this->sol = so;
        this->cacheManager = cache;
    }
    void handleClient (ostringstream* InputStream, ostringstream*
    OutputStream);
};


#endif //MILESTONE_2_MYTESTCLIENTHANDLER_H
