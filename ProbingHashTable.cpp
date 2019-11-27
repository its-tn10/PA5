#include "ProbingHashTable.h"

#include <utility>
#include <string>
#include <iostream>

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {
	this->capacity = 100000;
	this->table = new std::pair<std::string, int>[this->capacity];
}

// destructor
ProbingHashTable::~ProbingHashTable() {
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	int i = 0;
	while (i < this->capacity) {
		int j = (this->hash(key) + i) % this->capacity;
		if (this->table[j].first == key) { // Existing element, increment by val
			this->table[j].second += val;
			return;
		}
		if (this->table[j].first == "" && this->table[j].second == 0) {
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
	int p = this->get(key);
	if (this->table[p].first != "" && this->table[p].second != 0) {
		this->table[p].first = "";
		this->table[p].second = 0;
		this->size -= 1;
	} else {
		throw std::runtime_error("key not found");
	}
	return p;
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) {
	int i = 0, j = this->hash(key);
	while (i < this->capacity && this->table[j].first == "" && this->table[j].second == 0) {
		j = (this->hash(key) + i) % this->capacity;
		if (this->table[j].first == key)
			return j;
		i += 1;
	}
	return -1;
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