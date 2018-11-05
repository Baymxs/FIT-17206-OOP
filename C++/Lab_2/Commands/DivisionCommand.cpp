//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "DivisionCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/DivisionCommandCreator.h"
#include "../StackCalculator.h"

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeDivisionCommand() {
        CommandFactory::getInstance().registerCommand("/", new DivisionCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializeDivisionCommand();
}

void DivisionCommand::execute(std::vector<std::string>) {
    double argument_1 = StackCalculator::stack.top();
    StackCalculator::stack.pop();

    double argument_2 = StackCalculator::stack.top();
    StackCalculator::stack.pop();

    if (argument_2 != (double) 0)
        StackCalculator::stack.push(argument_2 / argument_1);
    else
        throw std::exception();
}