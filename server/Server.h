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
    template <class Problem, class Solution, class CacheData> class Server;
}
template <class Problem, class Solution, class CacheData>
class server_side::Server {
protected:
    bool run_server = true;
    thread server_running;
    int server_socket;
    int num_of_clients;
    sockaddr_in address;
public:
    Server(){}
    void open(int port, ClientHandler<Problem, Solution, CacheData>
            *clientHandler, int
    num_of_cli) {
        this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (this->server_socket == -1) {
            //error
            throw "Could not create a socket";
        }

        //bind socket to IP address
        // we first need to create the sockaddr obj.
        //in means IP4
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
        address.sin_port = htons(port);

        //the actual bind command
        if (bind(this->server_socket, (struct sockaddr *) &address, sizeof(address)) == -1) {
            throw "Could not bind the socket to an IP";
        }

        //making socket listen to the port
        this->num_of_clients =  num_of_cli;
        if (listen(this->server_socket, this->num_of_clients) == -1) { //can also set to SOMAXCON (max connections)
            throw "Error during listening command";
        } else {
            std::cout<<"Server is now listening ..."<<std::endl;
        }
    }
    void stop() {
        this->run_server = false;
        close(this->server_socket);
    }


    void read(int client_socket, ClientHandler<Problem, Solution, CacheData>
            *clientHandler) {
        ostringstream* InputStream = new ostringstream();
        ostringstream* OutputStream = new ostringstream();
        while(InputStream->str() != "end" && this->run_server) {
            char buffer[1024] = {0};
            InputStream->str("");
            OutputStream ->str("");
            int valread = ::read(client_socket, buffer, 1024);
            if (valread == 0) {
                break;
            }
            *InputStream << buffer;
            clientHandler->handleClient(InputStream, OutputStream);
            string* s = new string(OutputStream->str());
            write(client_socket , s->c_str(), s->size());
        }
        if (InputStream->str() == "end") {
            close(client_socket);
        } else if (!this->run_server) {
            close(this->server_socket);
        }
    }
    void listening(ClientHandler<Problem, Solution, CacheData> *clientHandler) {
        while (this->run_server) {
            // Setting timeout
            fd_set rfds;
            struct timeval timeout;
            timeout.tv_sec = 30;
            timeout.tv_usec = 0;
            FD_ZERO(&rfds);
            FD_SET(this->server_socket, &rfds);
            int iResult = select(this->server_socket + 1, &rfds, NULL, NULL,
                                 &timeout);
            int client_socket;
            if (iResult > 0) {
                // accepting a client
                client_socket = accept(this->server_socket,
                                       (struct sockaddr *) &address,
                                       (socklen_t *) &address);
                if (client_socket == -1) {
                    throw "Error accepting client";
                }
            } else {
                break;
            }
            this->read(client_socket, clientHandler);
        }
        if(!this->run_server) {
            close(this->server_socket);
        }
    }
    virtual void Parallel(ClientHandler<Problem, Solution, CacheData>
            *clientHandler) = 0;
};

#endif //MILESTONE_2_SERVER_H
