#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"

#include <string>
#include <list>
#include <vector>
#include <utility>


// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
    // TODO: insert additional variables needed here
    std::vector<std::list<std::pair<std::string, int>>> table;

    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key);
    void printAll(std::string filename);
};

#endif