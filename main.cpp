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
    DoubleHashTable table;

    ifstream ist{"dictionary.txt"};

    if (!ist)   throw runtime_error("cant open input file");
    string word;

    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    for (int i = 0; i < 50000; i++) {
    //while (ist >> word) 
        ist >> word;
        table.insert(word, 1);
    }
    end = chrono::system_clock::now();

   
    std::chrono::duration<double> elapsed_seconds = end - start; 
    std::time_t end_time = std::chrono::system_clock::to_time_t(end); 
    cout << elapsed_seconds.count() << endl;

    cout << table.get("astronaut") << endl;
    cout << table.remove("astronaut") << endl;
    cout << table.get("astronaut") << endl;

    table.printAll("output.txt");

    return 0;
}