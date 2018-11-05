#include <iostream>

#include "Command.h"
#include "CommandFactory.h"
#include "StackCalculator.h"

int main(int argc, char* argv[]) {
    auto *stackCalculator = new StackCalculator(argc, argv);
    stackCalculator->calculate();
    return 0;
}