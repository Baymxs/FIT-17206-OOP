#include <iostream>
#include <fstream>
#include "Command.h"
#include "CommandFactory.h"
#include "StackCalculator.h"

int main(int argc, char* argv[]) {

    if (argc == 1) {
        auto *stackCalculator = new StackCalculator(std::cin, std::cout);
        stackCalculator->calculate();
    } else if (argc == 2) {
        std::ifstream input_stream(argv[2]);
        std::ofstream output_stream(argv[2]);
        auto *stackCalculator = new StackCalculator(input_stream, output_stream);
        stackCalculator->calculate();
    } else std::cout << "Error: wrong number of arguments";

    return 0;
}