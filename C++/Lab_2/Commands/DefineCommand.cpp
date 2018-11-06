//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "DefineCommand.h"

#include "../Exceptions/ArgumentException.h"

#include "../CommandFactory.h"
#include "../CommandCreators/DefineCommandCreator.h"
#include "../StackCalculator.h"

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeDefineCommand() {
        CommandFactory::getInstance().registerCommand("DEFINE", new DefineCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializeDefineCommand();
}

void DefineCommand::execute(std::vector<std::string> arg_vector) {
    if (arg_vector.size() != 2)
        throw ArgumentException("Invalid number of arguments");

    int value_state = 0;

    for (int i = 0; i < arg_vector.size(); i++) {
        if (value_state == 2) value_state = 0;
        if (value_state == 0) StackCalculator::define_map[arg_vector[i]] = "";
        if (value_state == 1) StackCalculator::define_map[arg_vector[i - 1]] = arg_vector[i];
        value_state++;
    }
}