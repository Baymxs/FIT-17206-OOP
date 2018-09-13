//
// Created by Bayramov Nidjat on 12.09.18.
//

#include "WordCount.h"


WordCount::WordCount(int argc, char *input_file_name, char *output_file_name) {
    if (argc != 3) cerr << "Ouch! That hurts, because: more than 2 start-parameters" << "!\n";
    try {
        input_file.open(input_file_name, ios_base::in);
        output_file.open(output_file_name, ios_base::out);
    } catch (std::exception &ex) {
        cerr << "Ouch! That hurts, because: " << ex.what() << "!\n";
    }
}

void WordCount::readData() {
    int smb, break_point = 1;
    string word;

    while (break_point) {
        smb = input_file.get();
        if ((isalpha(smb) || isdigit(smb))) {
            word += (char) smb;
        } else if (!word.empty()){
            if (CSV_map.count(word) == 0) {
                CSV_map.insert( pair<string, int>(word, 1));
                count_of_words++;
            } else {
                CSV_map[word]++;
            }
            word.clear();
        }
        if (smb == EOF) break_point = 0;
    }
}

auto WordCount::makeSortedSet() {

    //Creating a lambda function to compare pairs of set container
    auto comparator =
            [](pair<string, int> element1, pair<string, int> element2) {
                return element1.second <= element2.second;
            };

    //Creating a new set sorted by value container that consists of pairs of the map container
    set<pair<string, int>, decltype(comparator)> CSV_set(CSV_map.begin(), CSV_map.end(), comparator);
    return CSV_set;
}

void WordCount::writeToFile() {
    auto CSV_set = makeSortedSet();
    for (pair<string, int> element : CSV_set) {
        output_file << element.first << "," << element.second << "," << (float)element.second/count_of_words << "%" << endl;
    }
}

void WordCount::go() {
    readData();
    makeSortedSet();
    writeToFile();
}