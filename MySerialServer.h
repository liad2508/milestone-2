//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_MYSERIALSERVER_H
#define MILESTONE_2_MYSERIALSERVER_H

#include "Server.h"
#define NUM_OF_CLIENTS 1

class MySerialServer: public server_side::Server {
public:
    void open(int port, ClientHandler clientHandler);
    void stop();
};


#endif //MILESTONE_2_MYSERIALSERVER_H
