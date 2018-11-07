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
    if (context.stackEmptiness() || context.stackSize() == 1)
        throw StackException("Not enough stack items");

    double argument_1 = context.stackTop();
    context.stackPop();

    double argument_2 = context.stackTop();
    context.stackPop();

    if (argument_1 != (double) 0)
        context.stackPush(argument_2 / argument_1);
    else
        throw DivisionByZeroException("Division by zero");
}