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
            int num = 0;
            ClientHandler (Solver<Problem, Solution>* so,
            CacheManager<CacheData>* cache) {
                this->sol = so;
                this->cacheManager = cache;
            }
            Solver<Problem, Solution> * getSolver() {return sol;}
            virtual bool handleClient(ostringstream *InputStream, ostringstream *
            OutputStream) = 0;
            virtual ClientHandler* clone() = 0;
            ~ClientHandler(){}
        };


#endif //MILESTONE_2_CLIENTHANDLER_H
