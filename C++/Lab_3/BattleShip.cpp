//
// Created by Bayramov Nidjat on 17.11.18.
//

#include "BattleShip.h"

#include <string>

#include "Factories/ViewFactory/ViewFactory.h"


BattleShip::BattleShip(const std::string &game_mode) {
    battleShipView = ViewFactory::getInstance().getView(game_mode);
    battleShipView->initializeModel(battleShipModel);
}

void BattleShip::startGame() {
}

