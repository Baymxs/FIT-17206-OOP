//
// Created by Bayramov Nidjat on 21.12.18.
//

#include <iostream>
#include "ShipPlacementWindow.h"
#include "../WindowFactory.h"
#include "../WindowCreators/ShipPlacementCreator.h"

//Initialize the window before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeShipPlacementWindow() {
        WindowFactory::getInstance().registerWindows("ShipPlacement", new ShipPlacementCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeShipPlacementWindow();
}

void ShipPlacementWindow::drawSprites() {
    for (auto sprite : sprites) {
        sprite->draw(getMainWindow());
    }
}

void ShipPlacementWindow::drawButtons() {
    for (auto button : buttons) {
        if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == button->getButtonName()) {
            button->setButtonSelectedTexture();
        } else {
            button->setButtonNormalTexture();
        }
        button->draw(getMainWindow());
    }
}

void ShipPlacementWindow::drawBattleField() {
    battleFieldSprite.drawBattleField(getMainWindow());
}

void ShipPlacementWindow::drawShip() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (auto deck : getBattleShipModel()->getShips()[getBattleShipModel()->getCurrentShip()]->getDecks()) {
                shipSprite.setSeaCellTexture(i, j);
            }
        }
    }

    for (auto deck : getBattleShipModel()->getShips()[getBattleShipModel()->getCurrentShip()]->getDecks()) {
        shipSprite.setShipCellTexture(deck.first, deck.second);
    }
    shipSprite.drawBattleField(getMainWindow());
}

void ShipPlacementWindow::render() {
    drawSprites();
    drawPlayers();
    drawButtons();
    drawBattleField();
    drawShip();
}

void ShipPlacementWindow::drawPlayers() {
}




