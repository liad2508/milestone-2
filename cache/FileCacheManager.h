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
#include <fstream>
#include <algorithm>
#include "CacheManager.h"

using namespace std;

template <class T>
class FileCacheManager: public CacheManager<T> {
private:
    unordered_map<string, T> cacheElements; // the cache elements
    map<string, list<string>::iterator> elementsIterators; // the location of
    // the elements in the cache
    list<string> indexes; // For the LRU algorithm
    int cacheCapacity; // Maximum capacity of the cache

public:

    // Cache Manage constructor
    FileCacheManager(int capacity) {
        this->cacheCapacity = capacity;

    }
    FileCacheManager() {

    }

    // Insert a new object to the cache
    void insert(string key, T obj) {
        // Inserting new data into the suitable file
        //this->writeToFile(key, obj);
        stringstream filename;
        // saving the object
        filename << key << ".bin";
        std::ofstream outFile(filename.str(), ios::out | ios::binary);
        outFile.write((char*)&obj, sizeof(obj));
        outFile.close();
        pair<string, T> newObj = pair<string, T> (key, obj);
        // If we exceeded the cache's capacity limit
        if ((this->cacheElements.size() + 1) > this->cacheCapacity) {
            this->cacheElements.erase(indexes.front());
            this->indexes.erase(indexes.begin());
        }
        this->cacheElements.insert(newObj);
        this->indexes.push_back(key);
        list<string>::iterator last = this->indexes.end();
        this->elementsIterators.insert(pair<string,list<string>::iterator>(key,
                                                                           (--last)));
    }

    // Get Object from Cache
    T get(string key) {
        T newObj;
        if (this->cacheElements.find(key) == this->cacheElements.end()) {
            stringstream filename;
            filename << key << ".bin";
            string* file = new string(filename.str());
            string* state = new string("r");
            FILE* tryOpen;
            tryOpen = std::fopen(filename.str().c_str(), state->c_str());
            if ( tryOpen != nullptr) {
                fclose(tryOpen);
                // reading
                std::ifstream inFile(filename.str(), ios::binary | ios::in);
                inFile.read((char*) &newObj, sizeof(newObj));
                inFile.close();
                if ((this->cacheElements.size() + 1) > this->cacheCapacity) {
                    this->cacheElements.erase(indexes.front());
                    this->indexes.erase(indexes.begin());
                }
                this->cacheElements.insert(pair<string, T>(key, newObj));
                this->indexes.push_back(key);
                return newObj;
            } else {
                return nullptr;
            }
        } else {
            newObj = cacheElements[key];
            list<string>::iterator start = this->elementsIterators[0];
            this->indexes.erase(start);
            this->indexes.push_back(key);
            list<string>::iterator last = this->indexes.end();
            this->elementsIterators[key] = (--last);
            return newObj;
        }
    }

    // Foreach function
    template <class func> void foreach(const func& f) {
        for (auto curPair = this->indexes.rbegin();
             curPair != this->indexes.rend(); curPair++) {
            f(this->cacheElements[*curPair]);
        }
    }
};

#endif //MILESTONE_2_FILECACHEMANAGER_H
