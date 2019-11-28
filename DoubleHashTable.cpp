#include "DoubleHashTable.h"

#include <utility>
#include <string>
#include <cmath>

#include <iostream>
using namespace std;

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
DoubleHashTable::DoubleHashTable() {
	this->capacity = 100000; // Update data structure to proper size
	this->table = new std::pair<std::string, int>[this->capacity];
}

// destructor
DoubleHashTable::~DoubleHashTable() {
}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
	int i = 0;
	long hash = this->hash(key), secondHash = this->secondHash(key); // Had segmentation fault, overflew
	while (i < this->capacity) {
		int j = (hash + i * secondHash) % this->capacity;
		if (this->table[j].first == key) { // Existing element, increment by val
			this->table[j].second += val;
			return;
		}
		if (this->table[j].first == "" && this->table[j].second == 0) { // Default values for NULL or empty pair
			this->table[j] = make_pair(key, val);
			this->size += 1;
			return;
		}
		i += 1;
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {
	int i = 0;
	long hash = this->hash(key), secondHash = this->secondHash(key); // Had segmentation fault, overflew
	while (i < this->capacity) {
		int j = (hash + i * secondHash) % this->capacity;
		if (this->table[j].first == key) {
			int p = this->table[j].second;
			this->table[j].first = "";
			this->table[j].second = 0;
			this->size -= 1;
			return p;
		}
		i += 1;
	}
	return -1; // Not found
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) {
	int i = 0;
	long hash = this->hash(key), secondHash = this->secondHash(key); // Had segmentation fault, overflew
	while (i < this->capacity) {
		int j = (hash + i * secondHash) % this->capacity;
		if (this->table[j].first == key)
			return this->table[j].second;
		i += 1;
	}
	return -1; // Not found
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {
	std::ofstream ofs{(filename)};

	if (!ofs)	throw std::runtime_error("cant open output file");
	
	for (int i = 0; i < this->capacity; i++) {
		if (this->table[i].first != "" && this->table[i].second != 0)
			ofs << this->table[i].first << ' ' << this->table[i].second << std::endl;
	}
}

// helper functions 
int DoubleHashTable::secondHash(std::string s) {
	int hash = 0;
	for (int i = 0; i < s.length(); i++) // Polynomial, x = 2
		hash += s.at(i) * pow(2, i);
	
	return hash;
}
