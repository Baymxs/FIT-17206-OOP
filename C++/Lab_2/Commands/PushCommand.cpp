//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "PushCommand.h"

#include "../CommandFactory.h"
#include "../CommandCreators/PushCommandCreator.h"
#include "../StackCalculator.h"

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
    StackCalculator::stack.push(std::stod(arg_vector[0]));
}