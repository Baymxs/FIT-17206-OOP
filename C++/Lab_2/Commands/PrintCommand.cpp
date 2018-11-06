//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "PrintCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/PrintCommandCreator.h"
#include "../StackCalculator.h"
#include "../Exceptions/StackException.h"
#include <fstream>
#include <iostream>

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePrintCommand() {
        CommandFactory::getInstance().registerCommand("PRINT", new PrintCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializePrintCommand();
}

void PrintCommand::execute(std::vector<std::string>) {
    if (StackCalculator::stack.empty())
        throw StackException("Not enough stack items");

    if (StackCalculator::input_stream_name == "stdin") std::cout << StackCalculator::stack.top();
    else {
        std::ofstream output_file(StackCalculator::input_stream_name);
        output_file << "\n" << StackCalculator::stack.top();
    }
}