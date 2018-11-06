//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "PushCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/PushCommandCreator.h"
#include "../StackCalculator.h"
#include "../Exceptions/ArgumentException.h"
#include "../Exceptions/NotNumberException.h"
#include <exception>


//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePushCommand() {
        CommandFactory::getInstance().registerCommand("PUSH", new PushCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializePushCommand();
}

void PushCommand::execute(std::vector<std::string> arg_vector) {
    if (arg_vector.size() != 1)
        throw ArgumentException("Invalid number of arguments");
    double arg_vector_double;
    try {
        arg_vector_double = std::stod(arg_vector[0]);
    } catch (std::exception &ex) {
        throw NotNumberException("Attempting to insert an item is not a number");
    }
    StackCalculator::stack.push(arg_vector_double);
}