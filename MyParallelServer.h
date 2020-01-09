//
// Created by idan on 09/01/2020.
//

#ifndef MILESTONE_2_MYPARALLELSERVER_H
#define MILESTONE_2_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer:server_side::Server {
public:
    void open(int port, ClientHandler clientHandler);
    void stop();
};


#endif //MILESTONE_2_MYPARALLELSERVER_H
