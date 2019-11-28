#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"

#include <iostream>
#include <fstream>
#include <string>

#include <chrono>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main() {
    string fileName;
    cout << "Enter the dictionary file: ";
    cin >> fileName;
    ifstream ist{fileName};

    if (!ist)   throw runtime_error("cant open input file");

    ChainingHashTable chainTable;
    ProbingHashTable probingTable;
    DoubleHashTable doubleHashTable;

    string word;
    while (ist >> word) {
        chainTable.insert(word, 1);
        probingTable.insert(word, 1);
        doubleHashTable.insert(word, 1);
    }
    
    chainTable.printAll("Chaining.txt");
    probingTable.printAll("Probing.txt");
    doubleHashTable.printAll("DoubleHashing.txt");

    return 0;
}