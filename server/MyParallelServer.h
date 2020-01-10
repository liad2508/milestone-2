//
// Created by idan on 09/01/2020.
//

#ifndef MILESTONE_2_MYPARALLELSERVER_H
#define MILESTONE_2_MYPARALLELSERVER_H

#include "Server.h"
#include <vector>
class MyParallelServer: public server_side::Server {
private:
    vector<thread> servers;
public:
    void Parallel(ClientHandler *clientHandler);
};


#endif //MILESTONE_2_MYPARALLELSERVER_H
