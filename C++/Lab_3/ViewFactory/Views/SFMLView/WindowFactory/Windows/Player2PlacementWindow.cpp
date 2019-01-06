//
// Created by Bayramov Nidjat on 31.12.18.
//

#include <iostream>
#include "Player2PlacementWindow.h"
#include "../WindowFactory.h"
#include "../WindowCreators/Player2PlacementCreator.h"

//Initialize the window before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePlayer2PlacementWindow() {
        WindowFactory::getInstance().registerWindows("Player2Placement", new Player2PlacementCreator());
        return true;
    }
    //Calling the global function
    auto state = initializePlayer2PlacementWindow();
}

void Player2PlacementWindow::drawSprites() {
    for (auto sprite : sprites) {
        sprite->draw(getMainWindow());
    }

    playerSprite.draw(getMainWindow());
}

void Player2PlacementWindow::drawButtons() {
    for (int i = 0; i < buttons.size(); i++) {
        if (i == 0 && getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == buttons[i]->getButtonName()) {
            buttons[i]->setButtonSelectedTexture();
        } else if (!getBattleShipModel()->isPlayer2Choice() && getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == buttons[i]->getButtonName()) {
            buttons[i]->setButtonSelectedTexture();
        } else if (getBattleShipModel()->isPlayer2Choice() && i) {
            buttons[i]->setButtonInvisibleTexture();
        } else {
            buttons[i]->setButtonNormalTexture();
        }
        buttons[i]->draw(getMainWindow());
    }
}

void Player2PlacementWindow::drawBattleField() {
    for (auto i : getBattleShipModel()->getPlayer2Ships()) {
        if (i->getLocationState()) {
            for (auto deck : i->getDecks()) {
                battleFieldSprite.setShipCellTexture(deck.first, deck.second);
            }
        }
    }
    battleFieldSprite.drawBattleField(getMainWindow());
}

void Player2PlacementWindow::drawShip() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            shipBattleFieldSprite.setTransparentCellTexture(i, j);
        }
    }
    if (getBattleShipModel()->isPlayer2Choice()) {
        for (auto deck : getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->getDecks()) {
            if (!getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->getAvailabilityState()) {
                shipBattleFieldSprite.setForbiddenCellTexture(deck.first, deck.second);
            } else {
                shipBattleFieldSprite.setShipCellTexture(deck.first, deck.second);
            }
        }
        for (auto cell : getBattleShipModel()->getPlayer2Ships()[getBattleShipModel()->getCurrentShip()]->getNearCells()) {
            if (!getBattleShipModel()->isShipPlaced(cell.first, cell.second)) {
                if (cell.first >= 0 && cell.first <= 9 && cell.second >= 0 && cell.second <= 9) {
                    shipBattleFieldSprite.setMarkedCellTexture(cell.first, cell.second);
                }
            }
        }
    }
    shipBattleFieldSprite.drawBattleField(getMainWindow());
}

void Player2PlacementWindow::render() {
    drawSprites();
    drawButtons();
    drawBattleField();
    drawShip();
}
