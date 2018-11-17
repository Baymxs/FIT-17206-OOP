//
// Created by Bayramov Nidjat on 07.11.18.
//

#include "ConsoleView.h"
#include "../ViewFactory.h"
#include "../ViewCreators/ConsoleCreator.h"

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeConsoleView() {
        ViewFactory::getInstance().registerViews("CONSOLE", new ConsoleCreator());
        return true;
    }
    //Calling the global function
    bool state = initializeConsoleView();
}

void ConsoleView::execute(std::vector<std::string>) {

}
