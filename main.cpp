#include <iostream>
#include <sys/socket.h>
#include "Server.h"

int main() {
    server_side::Server* s = new server_side::Server();
    ClientHandler* c = new ClientHandler();
    s->open(8000, *c , 1);
    return 0;
}
