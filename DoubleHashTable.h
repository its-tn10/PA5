#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include <utility>
#include <string>

#include "HashTable.h"


// Double hashing hash table class
class DoubleHashTable : public HashTable {
    private:
    // helper functions
    int secondHash(std::string s);

    // TODO: insert additional variables here
    std::pair<std::string, int> *table;

    public: 
    DoubleHashTable();
    ~DoubleHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key); 
    void printAll(std::string filename);
};

#endif