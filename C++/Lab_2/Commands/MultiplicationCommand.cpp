//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "MultiplicationCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/MultiplicationCommandCreator.h"
#include "../StackCalculator.h"
#include "../Exceptions/StackException.h"

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeMultiplicationCommand() {
        CommandFactory::getInstance().registerCommand("*", new MultiplicationCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializeMultiplicationCommand();
}

void MultiplicationCommand::execute(std::vector<std::string>, Context &context) {
    if (context.stackEmptiness() || context.stackSize() == 1)
        throw StackException("Not enough stack items");

    double argument_1 = context.stackTop();
    context.stackPop();

    double argument_2 = context.stackTop();
    context.stackPop();

    context.stackPush(argument_1 * argument_2);
}