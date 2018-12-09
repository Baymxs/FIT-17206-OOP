//
// Created by Bayramov Nidjat on 30.11.18.
//

#include <iostream>
#include "MenuController.h"

#include "../ControllerFactory.h"
#include "../ControllerCreators/MenuControllerCreator.h"

//Initialize the controller before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeMenuController() {
        ControllerFactory::getInstance().registerController("Menu", new MenuControllerCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeMenuController();
}

void MenuController::handleEvent(sf::Event event) {

}
