//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_CLIENTHANDLER_H
#define MILESTONE_2_CLIENTHANDLER_H
#include <iostream>

#include "../solver/Solver.h"
#include "../cache/CacheManager.h"
using namespace std;

template <class Problem, class Solution>
        class ClientHandler {
        protected:
            Solver<Problem, Solution> *sol;
            CacheManager <Solution> *cacheManager;
        public:
            ClientHandler (Solver<Problem, Solution>* so,
            CacheManager<Solution>* cache) {
                this->sol = so;
                this->cacheManager = cache;
            }
            virtual void
            handleClient(ostringstream *InputStream, ostringstream *
            OutputStream) = 0;

        };


#endif //MILESTONE_2_CLIENTHANDLER_H
