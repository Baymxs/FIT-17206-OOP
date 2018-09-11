#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

//
// Created by Bayramov Nidjat on 09.09.18.
//

using namespace std;
int main(int argc, char* argv[]) {
    //Creating an object fstream and link it with a file whose name is argv[1]
    ifstream fin(argv[1], ios_base::in);
    if (!fin) return 1;

    //Creating an object ofstream and link it with a file whose name is argv[2]
    ofstream fout(argv[2], ios_base::out);
    if (!fout) return 1;

    //Creating map container, where the key is of type string and the value is of type int
    map<string, int> CSV_map;

    int smb, break_point = 1, count_of_words = 0;
    string word;

    //Read the data by character, insert words into the map container with their frequency
    while (break_point) {
        smb = fin.get();
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
    //Creating a lambda function to compare pairs of set container
    auto comparator =
            [](pair<string, int> element1, pair<string, int> element2) {
                return element1.second <= element2.second;
            };

    //Creating a new set sorted by value container that consists of pairs of the map container
    set<pair<string, int>, decltype(comparator)> CSV_set(CSV_map.begin(), CSV_map.end(), comparator);

    //Using for foreach we go through the array and write to file a word, word frequency, word frequency in percent
    for (pair<string, int> element : CSV_set) {
        fout << element.first << "," << element.second << "," << (float)element.second/count_of_words << "%" << endl;
    }

    return 0;
}