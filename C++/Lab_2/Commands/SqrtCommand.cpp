//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "SqrtCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/SqrtCommandCreator.h"
#include "../StackCalculator.h"
#include "../Exceptions/StackException.h"
#include <math.h>

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePushCommand() {
        CommandFactory::getInstance().registerCommand("SQRT", new SqrtCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializePushCommand();
}

void SqrtCommand::execute(std::vector<std::string>, Context &context) {
    if (context.stackEmptiness())
        throw StackException("Not enough stack items");

    double argument_1 = context.stackTop();
    context.stackPop();

    context.stackPush(sqrt(argument_1));
}