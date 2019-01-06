//
// Created by Bayramov Nidjat on 31.12.18.
//

#include <iostream>
#include "Player2PlacementController.h"
#include "../ControllerFactory.h"
#include "../ControllerCreators/Player2PlacementControllerCreator.h"

//Initialize the controller before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePlayer2PlacementController() {
        ControllerFactory::getInstance().registerController("Player2Placement", new Player2PlacementControllerCreator());
        return true;
    }
    //Calling the global function
    auto state = initializePlayer2PlacementController();
}

void Player2PlacementController::handleEvent(sf::Event event) {
    int mouse_event_X, mouse_event_Y;
    switch (event.type) {
        case (sf::Event::KeyPressed):
            if (getBattleShipModel()->isPlayer2Choice()) {
                if (event.key.code == sf::Keyboard::Return) {
                    if (getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->getAvailabilityState()) {
                        getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->setLocationState(true);
                        if (getBattleShipModel()->getCurrentShip() == 9) {
                            getBattleShipModel()->setPlayer2Choice(false);
                        } else {
                            getBattleShipModel()->setCurrentShip(getBattleShipModel()->getCurrentShip() + 1);
                            getBattleShipModel()->setPlayer2ShipAvailability(getBattleShipModel()->getCurrentShip());
                        }
                    }
                } else if (event.key.code == sf::Keyboard::Down) {
                    if (getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->downDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->downShift();
                        getBattleShipModel()->setPlayer2ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Up) {
                    if (getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->upDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->upShift();
                        getBattleShipModel()->setPlayer2ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Left) {
                    if (getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->leftDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->leftShift();
                        getBattleShipModel()->setPlayer2ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Right) {
                    if (getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->rightDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->rightShift();
                        getBattleShipModel()->setPlayer2ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Space) {
                    getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->changeRotation();
                }
            }
            break;
        case sf::Event::MouseMoved:
            mouse_event_X = event.mouseMove.x, mouse_event_Y = event.mouseMove.y;
            if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("back");
            } else if (mouse_event_X >= 565 && mouse_event_X <= 788 && mouse_event_Y >= 540 && mouse_event_Y <= 588) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("battle");
            } else {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("");
            }
            break;
        case sf::Event::MouseButtonPressed:
            mouse_event_X = event.mouseButton.x, mouse_event_Y = event.mouseButton.y;
            if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->setGameStage("Menu");
            } else if (mouse_event_X >= 565 && mouse_event_X <= 788 && mouse_event_Y >= 540 && mouse_event_Y <= 588) {
                if (!getBattleShipModel()->isPlayer2Choice()) {
                    getBattleShipModel()->setGameStage("Player1Turn");
                }
            }
            break;
        default:
            break;
    }
}