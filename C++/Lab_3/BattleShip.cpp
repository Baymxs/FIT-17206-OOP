//
// Created by Bayramov Nidjat on 17.11.18.
//

#include "BattleShip.h"
#include "ViewFactory/ViewFactory.h"
#include "ViewFactory/Views/SFMLView/ControllerFactory/ControllerFactory.h"

#include <string>
#include <iostream>


BattleShip::BattleShip(const std::string &game_mode) {
    battleShipModel = new BattleShipModel(game_mode);
    battleShipView = ViewFactory::getInstance().getView(battleShipModel);
    battleShipController = ControllerFactory::getInstance().getController(battleShipModel);
}

void BattleShip::startGame() {
    while (battleShipView->getMainWindow()->isOpen()) {
        if (battleShipModel->getControllerChanges()) {
            battleShipController = ControllerFactory::getInstance().getController(battleShipModel);
            battleShipModel->setControllerChanges(false);
        }

        sf::Event event{};

        while (battleShipView->getMainWindow()->pollEvent(event)) {
            battleShipController->handleEvent(event);
        }

        battleShipView->getMainWindow()->clear(sf::Color::Blue);
        battleShipView->render();
        battleShipView->getMainWindow()->display();
    }
}

