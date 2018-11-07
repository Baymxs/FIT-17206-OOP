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

void PrintCommand::execute(std::vector<std::string>, Context &context) {
    if (context.stackEmptiness())
        throw StackException("Not enough stack items");

    context.output_stream << context.stackTop() << std::endl;
}