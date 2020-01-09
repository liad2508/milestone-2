//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_SERVER_H
#define MILESTONE_2_SERVER_H


#include "ClientHandler.h"

namespace server_side {

    class Server {

    public:
        virtual void open(int port, ClientHandler clientHandler) = 0;
        virtual void stop() = 0;

    };
}

#endif //MILESTONE_2_SERVER_H
