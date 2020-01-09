//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_CACHEMANAGER_H
#define MILESTONE_2_CACHEMANAGER_H

#include <iostream>
#include <string.h>

using namespace std;
template <class T>
class CacheManager {

public:
    virtual void insert(string key, T obj) = 0;
    virtual T get(string key) = 0;
};


#endif //MILESTONE_2_CACHEMANAGER_H
