//
// Created by Bayramov Nidjat on 17.11.18.
//

#include "BattleShip.h"
#include "ViewFactory/ViewFactory.h"
#include "ViewFactory/Views/SFMLView/ControllerFactory/ControllerFactory.h"

#include <string>
#include <iostream>


BattleShip::BattleShip(const std::string &game_mode) {
    battleShipModel = new BattleShipModel();
    battleShipView = ViewFactory::getInstance().getView(game_mode);
    battleShipController = ControllerFactory::getInstance().getController(battleShipModel->getGameStage());
}

void BattleShip::startGame() {
    //Run the BattleShipGame as long as the window is open
    while (battleShipView->getMainWindow()->isOpen()) {
        //Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (battleShipView->getMainWindow()->pollEvent(event)) {

            battleShipController->handleEvent(event);

            //"close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                battleShipView->getMainWindow()->close();
            }
        }

        battleShipView->getMainWindow()->clear(sf::Color::Red);
        battleShipView->render(battleShipModel);
        battleShipView->getMainWindow()->display();
    }
}

