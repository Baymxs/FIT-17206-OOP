//
// Created by Bayramov Nidjat on 12.09.18.
//

#ifndef WITH_OOP_WORDCOUNT_H
#define WITH_OOP_WORDCOUNT_H
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
class WordCount {
    ifstream input_file;
    ofstream output_file;

    map<string, int> CSV_map;
    int count_of_words = 0;

    public:
        WordCount(int argc, char *input_file_name, char *output_file_name);
        void readData();
        auto makeSortedSet();
        void writeToFile();
        void go();
};

#endif //WITH_OOP_WORDCOUNT_H
