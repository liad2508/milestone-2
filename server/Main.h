//
// Created by idan on 09/01/2020.
//

#ifndef MILESTONE_2_MAIN_H
#define MILESTONE_2_MAIN_H

#include "../solver/Solver.h"
#include "../solver/StringReverser.h"
#include "../cache/CacheManager.h"
#include "../cache/FileCacheManager.h"
#include "MySerialServer.h"
#include "../clientHandler/MyTestClientHandler.h"
#include "Server.h"
#include "MyParallelServer.h"
#include "../solution/Solution.h"
#include "../solution/Route.h"

#include "../clientHandler/MyClientHandler.h"
#include "../solver/BFS.h"
#include "../solver/DFS.h"
#include "../solver/A_Star.h"
#include "../solver/BestFirstSearch.h"
typedef int (*func)(State<myPoint*>*);
using namespace server_side;

namespace boot {
    class Main2;
}
int ffff(State<myPoint*>* s) {
    return 0;
}
func ttt = &ffff;

class boot::Main2{

public:
    static void main(string args[]) {
        string* file = new string("matrixes/Matrix_Funky");

        // Create cache
        CacheManager<Route*> *cache = new FileCacheManager<Route*>(10);
        cache->insert("default", new Route());

        // Create Astar
        Solver<Graph *, Route *> *sol = new A_Star<func>
                ("cache/ASTAR_solver", ttt);

        // Client Handler
        ClientHandler<Graph *, Route *, Route*> *clientHandler = (new
                    MyClientHandler
                    (sol, cache))->setNameOfFile(file);

        // Parallel server
        Server<Graph *, Route *, Route*> *s = new MyParallelServer<Graph *,
        Route *, Route*>();
        s->open(stoi(args[0]),clientHandler, 10);
        s->Parallel(clientHandler);

        
        /*** Serial Server option
            Graph* g = new Graph();
            g->InitializeGraph("Matrix_Funky_0");
            stringstream mat_file;
            int file_num = 0;
            int port = stoi(args[0]);
            string* file;

            // Create server
            Server<Graph *, Route *, Route*> *mySerialServer = new
                    MySerialServer<Graph *, Route *, Route*>();

            // Searcher
        //Solver<Graph *, Route *> *sol = new BFS("cache/BFS_solver");
        Solver<Graph *, Route *> *sol = new DFS("cache/BFS_solver");
            //Solver<Graph *, Route *> *sol = new BestFirstSearch
                    //("cache/BFS_solver");



            // Cache manager
            CacheManager<Route*> *cache = new FileCacheManager<Route*>(10);

            // Client handler
            mat_file << "matrixes/Matrix_Funky";
            file = new string(mat_file.str());
            ClientHandler<Graph *, Route *, Route*> *clientHandler = (new
                    MyClientHandler
                    (sol, cache))->setNameOfFile(file);

            // Open server's socket
            mySerialServer->open(port, clientHandler, 1);

            // Start handling
            thread t(&Server<Graph *, Route *, Route*>::listening,
                    mySerialServer,
                     clientHandler);
            //t.join(); ***/
    }
};



#endif //MILESTONE_2_MAIN_H
