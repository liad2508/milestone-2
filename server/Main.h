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

using namespace server_side;

namespace boot {
    class Main2;
}

class boot::Main2{

public:
    static void main(string args[]) {

        int port = stoi(args[0]);
        Solver<string,string>* solver = new StringReverser();
        CacheManager<Solution<const char*>>* cacheManager = new
                FileCacheManager<Solution<const char*>>(100);
        Server* mySerialServer = new MySerialServer();
        ClientHandler* clientHandler = new MyTestClientHandler(solver,
                cacheManager);
        mySerialServer->open(port, clientHandler, 1);
        thread t(&Server::listening,mySerialServer,clientHandler);
        t.join();
    }
};


#endif //MILESTONE_2_MAIN_H
