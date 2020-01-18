//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_CLIENTHANDLER_H
#define MILESTONE_2_CLIENTHANDLER_H
#include <iostream>

#include "../solver/Solver.h"
#include "../cache/CacheManager.h"
using namespace std;

template <class Problem, class Solution, class CacheData>
        class ClientHandler {
        protected:
            Solver<Problem, Solution> *sol;
            CacheManager <CacheData> *cacheManager;
        public:
            ClientHandler (Solver<Problem, Solution>* so,
            CacheManager<CacheData>* cache) {
                this->sol = so;
                this->cacheManager = cache;
            }
            Solver<Problem, Solution> * getSolver() {return sol;}
            virtual void
            handleClient(ostringstream *InputStream, ostringstream *
            OutputStream) = 0;

        };


#endif //MILESTONE_2_CLIENTHANDLER_H
