#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

// Chaining hash table class
class HashTable{
	protected:
	// helper functions
	int hash(std::string s); 

	// TODO: insert necessary variables for your hash table here

	public: 
	HashTable();
	~HashTable(); 
	virtual void insert(std::string key, int val) = 0; 
	virtual int remove(std::string key) = 0; 
	virtual int get(std::string key) = 0; 
	virtual void printAll(std::string filename) = 0;
	bool isEmpty() const; 
};

#endif