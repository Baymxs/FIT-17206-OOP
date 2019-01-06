//
// Created by Bayramov Nidjat on 31.12.18.
//

#include <iostream>
#include "Player1PlacementController.h"
#include "../ControllerFactory.h"
#include "../ControllerCreators/Player1PlacementControllerCreator.h"

//Initialize the controller before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePlayer1PlacementController() {
        ControllerFactory::getInstance().registerController("Player1Placement", new Player1PlacementControllerCreator());
        return true;
    }
    //Calling the global function
    auto state = initializePlayer1PlacementController();
}

void Player1PlacementController::handleEvent(sf::Event event) {
    int mouse_event_X, mouse_event_Y;
    switch (event.type) {
        case (sf::Event::KeyPressed):
            if (getBattleShipModel()->isPlayer1Choice()) {
                if (event.key.code == sf::Keyboard::Return) {
                    if (getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->getAvailabilityState()) {
                        getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->setLocationState(true);
                        if (getBattleShipModel()->getCurrentShip() == 9) {
                            getBattleShipModel()->setPlayer1Choice(false);
                            getBattleShipModel()->setCurrentShip(0);
                        } else {
                            getBattleShipModel()->setCurrentShip(getBattleShipModel()->getCurrentShip() + 1);
                            getBattleShipModel()->setPlayer1ShipAvailability(getBattleShipModel()->getCurrentShip());
                        }
                    }
                } else if (event.key.code == sf::Keyboard::Down) {
                    if (getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->downDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->downShift();
                        getBattleShipModel()->setPlayer1ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Up) {
                    if (getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->upDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->upShift();
                        getBattleShipModel()->setPlayer1ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Left) {
                    if (getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->leftDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->leftShift();
                        getBattleShipModel()->setPlayer1ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Right) {
                    if (getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->rightDecksShearPossibility()) {
                        getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->rightShift();
                        getBattleShipModel()->setPlayer1ShipAvailability(getBattleShipModel()->getCurrentShip());
                    }
                } else if (event.key.code == sf::Keyboard::Space) {
                    getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->changeRotation();
                }
            }
            break;
        case sf::Event::MouseMoved:
            mouse_event_X = event.mouseMove.x, mouse_event_Y = event.mouseMove.y;
            if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("back");
            } else if (mouse_event_X >= 624 && mouse_event_X <= 785 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("next");
            } else {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("");
            }
            break;
        case sf::Event::MouseButtonPressed:
            mouse_event_X = event.mouseButton.x, mouse_event_Y = event.mouseButton.y;
            if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->setGameStage("Menu");
            } else if (mouse_event_X >= 624 && mouse_event_X <= 785 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                if (!getBattleShipModel()->isPlayer1Choice()) {
                    getBattleShipModel()->setGameStage("Player2Placement");
                    getBattleShipModel()->setPlayer2Choice(true);
                }
            }
            break;
        default:
            break;
    }
}