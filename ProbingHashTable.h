#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "HashTable.h"

// Linear probing hash table class
class ProbingHashTable : public HashTable {
    private:
    // TODO: insert additional variables here

    public: 
    ProbingHashTable();
    ~ProbingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key); 
    void printAll(std::string filename);
};

#endif