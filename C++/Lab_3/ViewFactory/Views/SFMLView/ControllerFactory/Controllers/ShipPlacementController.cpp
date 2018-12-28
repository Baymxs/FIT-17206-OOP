//
// Created by Bayramov Nidjat on 20.12.18.
//

#include "ShipPlacementController.h"
#include <iostream>
#include "../ControllerFactory.h"
#include "../ControllerCreators/ShipPlacementControllerCreator.h"

//Initialize the controller before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeShipPlacementController() {
        ControllerFactory::getInstance().registerController("ShipPlacement", new ShipPlacementControllerCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeShipPlacementController();
}

void ShipPlacementController::handleEvent(sf::Event event) {
    int mouse_event_X, mouse_event_Y;
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Return) {
                getBattleShipModel()->setCurrentShip(getBattleShipModel()->getCurrentShip() + 1);
                std::cout << getBattleShipModel()->getCurrentShip() << std::endl;
            } else if (event.key.code == sf::Keyboard::Down) {
                getBattleShipModel()->getShips()[getBattleShipModel()->getCurrentShip()]->downShift();
            } else if (event.key.code == sf::Keyboard::Up) {
                getBattleShipModel()->getShips()[getBattleShipModel()->getCurrentShip()]->upShift();
            } else if (event.key.code == sf::Keyboard::Left) {
                getBattleShipModel()->getShips()[getBattleShipModel()->getCurrentShip()]->leftShift();
            } else if (event.key.code == sf::Keyboard::Right) {
                getBattleShipModel()->getShips()[getBattleShipModel()->getCurrentShip()]->rightShift();
            }
            break;
        case sf::Event::MouseMoved:
            mouse_event_X = event.mouseMove.x, mouse_event_Y = event.mouseMove.y;
            if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("back");
            } else {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("");
            }
            break;
        case sf::Event::MouseButtonPressed:
            mouse_event_X = event.mouseButton.x, mouse_event_Y = event.mouseButton.y;
            if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->setGameStage("Menu");
            }
            break;
        default:
            break;
    }
}
