#include <iostream>
#include <fstream>
#include "CSVParser.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        throw std::runtime_error("too many arguments");
    }

    std::ifstream file(argv[1]);

    CSVParser<int, std::string> parser(file);

    for (const std::tuple<int, std::string> &rs : parser) {
        std::cout << rs << std::endl;
    }

    return 0;
}