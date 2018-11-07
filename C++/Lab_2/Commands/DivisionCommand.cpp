//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "DivisionCommand.h"

#include "../Exceptions/StackException.h"
#include "../CommandFactory.h"
#include "../CommandCreators/DivisionCommandCreator.h"
#include "../StackCalculator.h"
#include "../Exceptions/DivisionByZero.h"

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

void DivisionCommand::execute(std::vector<std::string>, Context &context) {
    if (context.stack.empty() || context.stack.size() == 1)
        throw StackException("Not enough stack items");

    double argument_1 = context.stack.top();
    context.stack.pop();

    double argument_2 = context.stack.top();
    context.stack.pop();

    if (argument_1 != (double) 0)
        context.stack.push(argument_2 / argument_1);
    else
        throw DivisionByZeroException("Division by zero");
}