//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_MYSERIALSERVER_H
#define MILESTONE_2_MYSERIALSERVER_H

#include "Server.h"
#define NUM_OF_CLIENTS 1
template <class Problem, class Solution, class CacheData>
class MySerialServer: public server_side::Server<Problem, Solution, CacheData> {
public:

};


#endif //MILESTONE_2_MYSERIALSERVER_H
