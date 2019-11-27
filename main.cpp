#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ProbingHashTable table;

    ifstream ist{"dictionary.txt"};

    if (!ist)   throw runtime_error("cant open input file");
    string word;
    while (ist >> word) 
        table.insert(word, 1);
    

    table.printAll("output.txt");

    return 0;
}