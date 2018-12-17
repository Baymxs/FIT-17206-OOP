//
// Created by Bayramov Nidjat on 16.12.18.
//

#include <iostream>
#include "OptionsController.h"
#include "../ControllerFactory.h"
#include "../ControllerCreators/OptionsControllerCreator.h"

//Initialize the controller before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeOptionsController() {
        ControllerFactory::getInstance().registerController("Options", new OptionsControllerCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeOptionsController();
}

void OptionsController::handleEvent(sf::Event event) {
    int mouse_event_X, mouse_event_Y;
    switch (event.type) {
        case sf::Event::MouseMoved:
            mouse_event_X = event.mouseMove.x, mouse_event_Y = event.mouseMove.y;
            if (mouse_event_X >= 242 && mouse_event_X <= 307 && mouse_event_Y >= 203 && mouse_event_Y <= 268) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("left_selection_button");
            } else if (mouse_event_X >= 462 && mouse_event_X <= 530 && mouse_event_Y >= 203 && mouse_event_Y <= 268) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("right_selection_button");
            } else if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("back_button");
            } else {
                getBattleShipModel()->getBattleShipMenuModel().setMenuMove("");
            }
            break;
        case sf::Event::MouseButtonPressed:
            mouse_event_X = event.mouseButton.x, mouse_event_Y = event.mouseButton.y;
            if (mouse_event_X >= 242 && mouse_event_X <= 307 && mouse_event_Y >= 203 && mouse_event_Y <= 268) {
                if (getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection() == 1) {
                    getBattleShipModel()->getBattleShipMenuModel().setVolumeSelection(2);
                } else {
                    getBattleShipModel()->getBattleShipMenuModel().setVolumeSelection(getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection() - 1);
                }
            } else if (mouse_event_X >= 462 && mouse_event_X <= 530 && mouse_event_Y >= 203 && mouse_event_Y <= 268) {
                if (getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection() == 2) {
                    getBattleShipModel()->getBattleShipMenuModel().setVolumeSelection(1);
                } else {
                    getBattleShipModel()->getBattleShipMenuModel().setVolumeSelection(getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection() + 1);
                }
            } else if (mouse_event_X >= 10 && mouse_event_X <= 176 && mouse_event_Y >= 540 && mouse_event_Y <= 590) {
                getBattleShipModel()->setGameStage("Menu");
            }
            break;
        default:
            break;
    }
}
