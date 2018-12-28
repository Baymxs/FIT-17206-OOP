//
// Created by Bayramov Nidjat on 30.11.18.
//

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
    int mouse_event_X, mouse_event_Y;
    switch (event.type) {
        case sf::Event::MouseMoved:
            mouse_event_X = event.mouseMove.x, mouse_event_Y = event.mouseMove.y;
            if (mouse_event_X >= 275 && mouse_event_X <= 525 && mouse_event_Y >= 200 && mouse_event_Y <= 263) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("start");
            } else if (mouse_event_X >= 90 && mouse_event_X <= 155 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("left_selection_button1");
            } else if (mouse_event_X >= 335 && mouse_event_X <= 400 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("right_selection_button1");
            } else if (mouse_event_X >= 400 && mouse_event_X <= 465 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("left_selection_button2");
            } else if (mouse_event_X >= 645 && mouse_event_X <= 740 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("right_selection_button2");
            } else if (mouse_event_X >= 245 && mouse_event_X <= 555 && mouse_event_Y >= 419 && mouse_event_Y <= 481) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("options");
            } else if (mouse_event_X >= 311 && mouse_event_X <= 478 && mouse_event_Y >= 496 && mouse_event_Y <= 556) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("exit");
            } else {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("");
            }
            break;
        case sf::Event::MouseButtonPressed:
            mouse_event_X = event.mouseButton.x, mouse_event_Y = event.mouseButton.y;
            if (mouse_event_X >= 275 && mouse_event_X <= 525 && mouse_event_Y >= 200 && mouse_event_Y <= 263) {
                getBattleShipModel()->setGameStage("ShipPlacement");
            } else if (mouse_event_X >= 245 && mouse_event_X <= 525 && mouse_event_Y >= 424 && mouse_event_Y <= 486) {
                    getBattleShipModel()->setGameStage("Options");
            } else if (mouse_event_X >= 90 && mouse_event_X <= 155 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                if (getBattleShipModel()->getBattleShipMenuModel().getPlayer1() == 1) {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer1(3);
                } else {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer1(getBattleShipModel()->getBattleShipMenuModel().getPlayer1() - 1);
                }
            } else if (mouse_event_X >= 335 && mouse_event_X <= 400 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                if (getBattleShipModel()->getBattleShipMenuModel().getPlayer1() == 3) {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer1(1);
                } else {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer1(getBattleShipModel()->getBattleShipMenuModel().getPlayer1() + 1);
                }
            } else if (mouse_event_X >= 400 && mouse_event_X <= 465 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                if (getBattleShipModel()->getBattleShipMenuModel().getPlayer2() == 1) {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer2(3);
                } else {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer2(getBattleShipModel()->getBattleShipMenuModel().getPlayer2() - 1);
                }
            } else if (mouse_event_X >= 645 && mouse_event_X <= 740 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                if (getBattleShipModel()->getBattleShipMenuModel().getPlayer2() == 3) {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer2(1);
                } else {
                    getBattleShipModel()->getBattleShipMenuModel().setPlayer2(getBattleShipModel()->getBattleShipMenuModel().getPlayer2() + 1);
                }
            } else if (mouse_event_X >= 311 && mouse_event_X <= 478 && mouse_event_Y >= 496 && mouse_event_Y <= 556) {
                getBattleShipModel()->setGameStage("Exit");
            }
        break;
        default:
            break;
    }
}
