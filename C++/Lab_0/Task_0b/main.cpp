#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;
int main(int argc, char* argv[]) {
    ifstream fin(argv[1], ios_base::in);
    if (!fin) return 1;

    ofstream fout(argv[2], ios_base::out);
    if (!fout) return 1;

    map<string, int> CSV_map;

    int smb, break_point = 1, count_of_words = 0;
    string word;

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

    auto comparator =
            [](pair<string, int> element1, pair<string, int> element2) {
                return element1.second <= element2.second;
            };

    set<pair<string, int>, decltype(comparator)> CSV_set(CSV_map.begin(), CSV_map.end(), comparator);

    for (pair<string, int> element : CSV_set) {
        fout << element.first << "," << element.second << "," << (float)element.second/count_of_words << "%" << endl;
    }

    return 0;
}