//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_SERVER_H
#define MILESTONE_2_SERVER_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sstream>
#include <cstring>
#include "Server.h"
#include <thread>
#include <pthread.h>
#include "../clientHandler/ClientHandler.h"
using namespace std;

namespace server_side {
    class Server;
}

class server_side::Server {
protected:
    bool run_server = true;
    thread server_running;
    int server_socket;
    sockaddr_in address;
public:
    Server(){}
    void open(int port, ClientHandler *clientHandler, int num_of_clients);
    void stop();
    void read(int client_socket, ClientHandler *clientHandler);
    void listening(ClientHandler *clientHandler);
};

#endif //MILESTONE_2_SERVER_H
