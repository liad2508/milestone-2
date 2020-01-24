//
// Created by liad on 09/01/2020.
//

#ifndef MILESTONE_2_FILECACHEMANAGER_H
#define MILESTONE_2_FILECACHEMANAGER_H

#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <sstream>
#include <ostream>
#include <istream>
#include <mutex>
#include <fstream>
#include <algorithm>
#include "CacheManager.h"
#include "../solution/Solution.h"

using namespace std;
template <class T>
class FileCacheManager: public CacheManager<T> {
private:
    mutex m1;
    mutex m2;
    mutex m3;
    mutex m4;
    map<string, T> cacheElements; // the cache elements
    map<string, list<string>::iterator> elementsIterators; // the
    // location of
    // the elements in the cache
    list<string>* indexes; // For the LRU algorithm
    int cacheCapacity; // Maximum capacity of the cache

public:

    // Cache Manage constructor
    FileCacheManager(int capacity) {
        this->cacheCapacity = capacity;
        this->indexes = new list<string>;

    }
    FileCacheManager() {
        this->cacheCapacity = 10;
        this->indexes = new list<string>;
    }

    // Insert a new object to the cache
    void insert(string key, T obj) {
        m1.lock();
        // Inserting new data into the suitable file
        //this->writeToFile(key, obj);
        std::ofstream outFile(key.c_str());
        obj->toFile(&outFile);
        outFile.close();
        // If we exceeded the cache's capacity limit
        LRU(key, obj);
        list<string>::iterator last = this->indexes->end();
        --last;
        this->elementsIterators.insert({key,last});
        m1.unlock();
    }
    void LRU(string key, T obj) {
        m2.lock();
        if ((this->cacheElements.size() + 1) > this->cacheCapacity) {
            this->cacheElements.erase(indexes->front());
            this->indexes->erase(indexes->begin());
        }
        this->cacheElements.insert({key, obj});
        this->indexes->push_back(key);
        m2.unlock();
    }
    // Get Object from Cache
    T get(string key) {
        m3.lock();
        T newObj;
        if (this->cacheElements.find(key) == this->cacheElements.end()) {
            stringstream filename;
            filename << key;
            string* file = new string(filename.str());
            string* state = new string("r");
            FILE* tryOpen;
            tryOpen = std::fopen(filename.str().c_str(), state->c_str());
            if ( tryOpen != nullptr) {
                fclose(tryOpen);
                // reading
                std::ifstream inFile(filename.str());
                if (filename.str() ==
                "cache/ASTAR_solver_15917437370524430963") {
                    cout << "ss" << endl;
                }
                newObj = this->cacheElements["default"]->fromFile(&inFile);
                inFile.close();
                LRU(key, newObj);
                m3.unlock();
                return newObj;
            }
        } else {
            newObj = cacheElements[key];
            list<string>::iterator start = this->elementsIterators[key];
            this->indexes->erase(start);
            this->indexes->push_back(key);
            list<string>::iterator last = this->indexes->end();
            this->elementsIterators[key] = (--last);
            m3.unlock();
            return newObj;
        }
        m3.unlock();
        throw "Data is not in cache";
    }

    // Foreach function
    template <class func> void foreach(const func& f) {
        for (auto curPair = this->indexes->rbegin();
             curPair != this->indexes->rend(); curPair++) {
            f(this->cacheElements[*curPair]);
        }
    }
    ~FileCacheManager(){
        delete this->indexes;
    }
};

#endif //MILESTONE_2_FILECACHEMANAGER_H
