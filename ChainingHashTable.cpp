#include "ChainingHashTable.h"

#include <utility>
#include <string>
#include <fstream>

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() {
	this->capacity = 60000; // Update data structure to proper size
	this->table.resize(this->capacity);
}

// destructor
ChainingHashTable::~ChainingHashTable() {
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	std::list<std::pair<std::string, int>>::iterator it;
	for (it = this->table.at(this->hash(key)).begin(); it != this->table.at(this->hash(key)).end(); ++it) { // Going through each element in list
		if ((*it).first == key) { // Found an existing key, just increment the value
			(*it).second += val;
			return;
		}
	}
	// No existing key, create a new pair
	std::pair<std::string, int> pair = make_pair(key, val);
	this->table.at(this->hash(key)).push_back(pair);
	this->size += 1;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	std::list<std::pair<std::string, int>>::iterator it;
	int rtnVal = -1;
	for (it = this->table.at(this->hash(key)).begin(); it != this->table.at(this->hash(key)).end(); ++it) {
		if ((*it).first == key) { // Going through each element in list to find correct key
			rtnVal = (*it).second;
			this->table.at(this->hash(key)).erase(it);
			this->size -= 1;
			return rtnVal;
		}
	}
	return -1; // Not found
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	std::list<std::pair<std::string, int>>::iterator it;
	for (it = this->table.at(this->hash(key)).begin(); it != this->table.at(this->hash(key)).end(); ++it) {
		if ((*it).first == key)
			return (*it).second;
	}
	return -1; // Not found
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {
	std::ofstream ofs{(filename)};

	if (!ofs)	throw std::runtime_error("cant open output file");
	
	std::list<std::pair<std::string, int>>::iterator it;
	for (int i = 0; i < this->table.size(); i++) {
		for (it = this->table.at(i).begin(); it != this->table.at(i).end(); ++it) 
			ofs << (*it).first << ' ' << (*it).second << std::endl;
	}
}