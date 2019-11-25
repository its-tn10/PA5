#include "HashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// default constructor
HashTable::HashTable() {
}

// destructor
HashTable::~HashTable() {
}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(std::string s) {
	int hash = 0;
	for (int i = 0; i < s.length(); i++) 
		hash = (2 * hash + s.at(i)) % this->capacity;
	
	return hash;
}

// returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const {
	return this->size == 0;
}
