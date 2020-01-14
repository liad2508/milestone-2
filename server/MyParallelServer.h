//
// Created by idan on 09/01/2020.
//

#ifndef MILESTONE_2_MYPARALLELSERVER_H
#define MILESTONE_2_MYPARALLELSERVER_H

#include "Server.h"
#include <vector>
template <class Problem, class Solution>
class MyParallelServer: public server_side::Server<Problem, Solution> {
private:
    vector<thread> servers;
public:
    void Parallel(ClientHandler<Problem, Solution> *clientHandler) {
        for (int waiting_for_all = this->num_of_clients; waiting_for_all > 0;
             waiting_for_all--) {
            this->servers.push_back(thread(&server_side::Server<Problem,
                    Solution>::listening, this, clientHandler));
        }
        auto last_server = this->servers.end();
        for(auto server = this->servers.begin(); server != last_server; server++) {
            server->join();
        }
    }
};


#endif //MILESTONE_2_MYPARALLELSERVER_H
