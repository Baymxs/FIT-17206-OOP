#include <iostream>
#include "WordCount.h"
int main(int argc, char* argv[]) {
    auto *wordCount = new WordCount(argc, argv[1], argv[2]);
    wordCount->go();
    delete wordCount;
    return 0;
}