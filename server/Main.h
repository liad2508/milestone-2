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
#include "../solution/Solution.h"
#include "../solution/Route.h"

#include "../clientHandler/MyClientHandler.h"
#include "../solver/BFS.h"

using namespace server_side;

namespace boot {
    class Main2;
}

class boot::Main2{

public:
    static void main(string args[]) {
            Graph* g = new Graph();
            g->InitializeGraph("matrix_test.txt");


//
//
//            stringstream mat_file;
//            int file_num = 0;
//            int port = stoi(args[0]);
//            string* file;
//
//            // Create server
//            Server<Graph *, Route *> *mySerialServer = new MySerialServer<Graph *, Route *>();
//
//            // Searcher
//            Solver<Graph *, Route *> *sol = new BFS("BFS_solver");
//
//            // Cache manager
//            CacheManager<Route *> *cache = new FileCacheManager<Route *>();
//
//            // Client handler
//            mat_file << "Matrix_Funky_" << file_num;
//            file_num++;
//            file = new string(mat_file.str());
//            ClientHandler<Graph *, Route *> *clientHandler = (new MyClientHandler
//                    (sol, cache))->setNameOfFile(file);
//
//            // Open server's socket
//            mySerialServer->open(port, clientHandler, 1);
//
//            // Start handling
//            thread t(&Server<Graph *, Route *>::listening, mySerialServer,
//                     clientHandler);
//            t.join();
    }
};


#endif //MILESTONE_2_MAIN_H
