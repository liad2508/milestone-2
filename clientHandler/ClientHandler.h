//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_CLIENTHANDLER_H
#define MILESTONE_2_CLIENTHANDLER_H
#include <iostream>

#include "../solver/Solver.h"
using namespace std;
class ClientHandler {

public:
    virtual void handleClient (ostringstream* InputStream, ostringstream*
    OutputStream) = 0;

};


#endif //MILESTONE_2_CLIENTHANDLER_H
