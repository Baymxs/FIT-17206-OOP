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
            } else if (mouse_event_X >= 245 && mouse_event_X <= 555 && mouse_event_Y >= 419 && mouse_event_Y <= 481) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("options");
            } else if (mouse_event_X >= 311 && mouse_event_X <= 478 && mouse_event_Y >= 496 && mouse_event_Y <= 556) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("exit");
            } else if (!getBattleShipModel()->isGameStarted()) {
                if (mouse_event_X >= 90 && mouse_event_X <= 155 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    getBattleShipModel()->getBattleShipMenuModel().setMenuMove("left_selection_button1");
                } else if (mouse_event_X >= 335 && mouse_event_X <= 400 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    getBattleShipModel()->getBattleShipMenuModel().setMenuMove("right_selection_button1");
                } else if (mouse_event_X >= 400 && mouse_event_X <= 465 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    getBattleShipModel()->getBattleShipMenuModel().setMenuMove("left_selection_button2");
                } else if (mouse_event_X >= 645 && mouse_event_X <= 740 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    getBattleShipModel()->getBattleShipMenuModel().setMenuMove("right_selection_button2");
                }
            }
            else {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("");
            }
            break;
        case sf::Event::MouseButtonPressed:
            mouse_event_X = event.mouseButton.x, mouse_event_Y = event.mouseButton.y;
            if (mouse_event_X >= 275 && mouse_event_X <= 525 && mouse_event_Y >= 200 && mouse_event_Y <= 263) {
                getBattleShipModel()->setGameStartedState(true);
                if (getBattleShipModel()->isPlayer1Choice()) {
                    getBattleShipModel()->setGameStage("Player1Placement");
                } else if (getBattleShipModel()->isPlayer2Choice()) {
                    getBattleShipModel()->setGameStage("Player2Placement");
                } else if (getBattleShipModel()->isAllShipsAreLocated1() && !getBattleShipModel()->isAllShipsAreLocated2()) {
                    getBattleShipModel()->setGameStage("Player1Placement");
                } else {
                    getBattleShipModel()->setGameStage("Player2Placement");
                }
            }
            else if (mouse_event_X >= 245 && mouse_event_X <= 525 && mouse_event_Y >= 424 && mouse_event_Y <= 486) {
                    getBattleShipModel()->setGameStage("Options");
            } else if (!getBattleShipModel()->isGameStarted())  {
                if (mouse_event_X >= 90 && mouse_event_X <= 155 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    if (getBattleShipModel()->getPlayer1() == 1) {
                        getBattleShipModel()->setPlayer1(3);
                    } else {
                        getBattleShipModel()->setPlayer1(getBattleShipModel()->getPlayer1() - 1);
                    }
                } else if (mouse_event_X >= 335 && mouse_event_X <= 400 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    if (getBattleShipModel()->getPlayer1() == 3) {
                        getBattleShipModel()->setPlayer1(1);
                    } else {
                        getBattleShipModel()->setPlayer1(getBattleShipModel()->getPlayer1() + 1);
                    }
                } else if (mouse_event_X >= 400 && mouse_event_X <= 465 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    if (getBattleShipModel()->getPlayer2() == 1) {
                        getBattleShipModel()->setPlayer2(3);
                    } else {
                        getBattleShipModel()->setPlayer2(getBattleShipModel()->getPlayer2() - 1);
                    }
                } else if (mouse_event_X >= 645 && mouse_event_X <= 740 && mouse_event_Y >= 349 && mouse_event_Y <= 417) {
                    if (getBattleShipModel()->getPlayer2() == 3) {
                        getBattleShipModel()->setPlayer2(1);
                    } else {
                        getBattleShipModel()->setPlayer2(getBattleShipModel()->getPlayer2() + 1);
                    }
                }
            } else if (mouse_event_X >= 311 && mouse_event_X <= 478 && mouse_event_Y >= 496 && mouse_event_Y <= 556) {
                getBattleShipModel()->setGameStage("Exit");
            }
        break;
        default:
            break;
    }
}
