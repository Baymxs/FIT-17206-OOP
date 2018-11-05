//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "PlusCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/PlusCommandCreator.h"
#include "../StackCalculator.h"

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePlusCommand() {
        CommandFactory::getInstance().registerCommand("+", new PlusCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializePlusCommand();
}

void PlusCommand::execute(std::vector<std::string>) {
    double argument_1 = StackCalculator::stack.top();
    StackCalculator::stack.pop();

    double argument_2 = StackCalculator::stack.top();
    StackCalculator::stack.pop();

    StackCalculator::stack.push(argument_1 + argument_2);
}