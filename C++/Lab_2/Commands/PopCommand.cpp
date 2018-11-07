//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "PopCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/PopCommandCreator.h"
#include "../StackCalculator.h"
#include "../Exceptions/StackException.h"

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePopCommand() {
        CommandFactory::getInstance().registerCommand("POP", new PopCommandCreator());
        return true;
    }
    //Calling the global function
    bool state = initializePopCommand();
}

void PopCommand::execute(std::vector<std::string>, Context &context) {
    if (context.stackEmptiness())
        throw StackException("Not enough stack items");
    context.stackPop();
}