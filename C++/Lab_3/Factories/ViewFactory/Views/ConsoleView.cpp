//
// Created by Bayramov Nidjat on 07.11.18.
//

#include "ConsoleView.h"
#include "../ViewFactory.h"
#include "../ViewCreators/ConsoleCreator.h"
#include "../../WindowFactory/WindowFactory.h"

//Initialize the command before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeConsoleView() {
        ViewFactory::getInstance().registerViews("Console", new ConsoleCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeConsoleView();
}

void ConsoleView::render() {
    battleShipWindow = WindowFactory::getInstance().getView(battleShipModel->getGameStage());
}

void ConsoleView::initializeModel(BattleShipModel &battleShipModel_1) {
    battleShipModel = &battleShipModel_1;
}
