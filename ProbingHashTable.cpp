#include "ProbingHashTable.h"

#include <utility>
#include <string>
#include <iostream>

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {
	this->capacity = 100000; // Update data structure to proper size
	this->table = new std::pair<std::string, int>[this->capacity];
}

// destructor
ProbingHashTable::~ProbingHashTable() {
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	int i = 0, hash = this->hash(key);
	while (i < this->capacity) {
		int j = (hash + i) % this->capacity;
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
	// full
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	int i = 0, hash = this->hash(key), j = hash, p = -1;
	while (i < this->capacity) {
		j = (hash + i) % this->capacity;
		if (this->table[j].first == key) {
			p = this->table[j].second;
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
int ProbingHashTable::get(std::string key) {
	int i = 0, hash = this->hash(key), j = hash;
	while (i < this->capacity) {
		j = (hash + i) % this->capacity;
		if (this->table[j].first == key)
			return this->table[j].second;
		i += 1;
	}
	return -1; // Not found
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {
	std::ofstream ofs{(filename)};

	if (!ofs)	throw std::runtime_error("cant open output file");
	
	for (int i = 0; i < this->capacity; i++) {
		if (this->table[i].first != "" && this->table[i].second != 0)
			ofs << this->table[i].first << ' ' << this->table[i].second << std::endl;
	}
}