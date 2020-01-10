//
// Created by idan on 09/01/2020.
//

#include "MyParallelServer.h"
void MyParallelServer::Parallel(ClientHandler *clientHandler) {
    for (int waiting_for_all = num_of_clients; waiting_for_all > 0;
    waiting_for_all--) {
        this->servers.push_back(thread(&server_side::Server::listening, this,
                clientHandler));

    }
    auto last_server = this->servers.end();
    for(auto server = this->servers.begin(); server != last_server; server++) {
        server->join();
    }
}