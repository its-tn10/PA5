#include "ChainingHashTable.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ChainingHashTable table;

    ifstream ist{"dictionary.txt"};

    if (!ist)   throw runtime_error("cant open input file");
    string word;
    while (ist >> word) {
        table.insert(word, 1);
    }

    table.printAll("output.txt");

    return 0;
}