//
// Created by liad on 09/01/2020.
//


#include "Server.h"

void server_side::Server::read(int client_socket, ClientHandler clientHandler) {
    char buffer[1024] = {0};
    ostringstream* InputStream = new ostringstream();
    ostringstream* OutputStream = new ostringstream();
    while(InputStream->str() != "end" && this->run_server) {
        int valread = ::read(client_socket, buffer, 1024);
        *InputStream << buffer;
        //clientHandler.handleClient(InputStream, OutputStream);
        const char* answer = OutputStream->str().c_str();
        send(client_socket , answer , strlen(answer) , 0 );
    }

    if (InputStream->str() == "end") {
        close(client_socket);
    }
}

void server_side::Server::stop() {
    this->run_server = false;
    this->server_running.join();
    close(this->server_socket);
}

void server_side::Server::open(int port, ClientHandler clientHandler,
        int num_of_clients) {
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
    if (listen(this->server_socket, num_of_clients) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    thread t(&server_side::Server::listening, this, clientHandler);
    t.detach();
}

void server_side::Server::listening(ClientHandler clientHandler){
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
        }
        this->server_running = thread(&server_side::Server::read, this,
                                      client_socket,
                                      clientHandler);
        this->server_running.detach();
    }
}