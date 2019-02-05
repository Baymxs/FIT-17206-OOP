//
// Created by Bayramov Nidjat on 31.12.18.
//

#include <iostream>
#include "Player1PlacementWindow.h"
#include "../WindowFactory.h"
#include "../WindowCreators/Player1PlacementCreator.h"

//Initialize the window before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializePlayer1PlacementWindow() {
        WindowFactory::getInstance().registerWindows("Player1Placement", new Player1PlacementCreator());
        return true;
    }
    //Calling the global function
    auto state = initializePlayer1PlacementWindow();
}

void Player1PlacementWindow::drawSprites() {
    for (auto sprite : sprites) {
        sprite->draw(getMainWindow());
    }
    playerSprite.draw(getMainWindow());
}

void Player1PlacementWindow::drawButtons() {
    for (int i = 0; i < buttons.size(); i++) {
        if ((i == 0 || i == 2) && getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == buttons[i]->getButtonName()) {
            buttons[i]->setButtonSelectedTexture();
        } else if (!getBattleShipModel()->isPlayer1Choice() && getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == buttons[i]->getButtonName()) {
            buttons[i]->setButtonSelectedTexture();
        } else if (getBattleShipModel()->isPlayer1Choice() && (i == 1)) {
            buttons[i]->setButtonInvisibleTexture();
        } else {
            buttons[i]->setButtonNormalTexture();
        }
        buttons[i]->draw(getMainWindow());
    }
}

void Player1PlacementWindow::drawBattleField() {
    if (!getBattleShipModel()->isPlayer1Choice()) {

    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            battleFieldSprite.setTransparentCellTexture(i, j);
        }
    }
    for (auto i : getBattleShipModel()->getPlayer1Ships()) {
        if (i->getLocationState()) {
            for (auto deck : i->getDecks()) {
                battleFieldSprite.setShipCellTexture(deck.first, deck.second);
            }
        }
    }
    battleFieldSprite.drawBattleField(getMainWindow());
}

void Player1PlacementWindow::drawShip() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            shipBattleFieldSprite.setTransparentCellTexture(i, j);
        }
    }
    if (getBattleShipModel()->isPlayer1Choice()) {
        for (auto deck : getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->getDecks()) {
            if (!getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->getAvailabilityState()) {
                shipBattleFieldSprite.setForbiddenCellTexture(deck.first, deck.second);
            } else {
                shipBattleFieldSprite.setShipCellTexture(deck.first, deck.second);
            }
        }
        for (auto cell : getBattleShipModel()->getPlayer1Ships()[getBattleShipModel()->getCurrentShip()]->getNearCells()) {
            if (!getBattleShipModel()->isShipPlaced(cell.first, cell.second)) {
                if (cell.first >= 0 && cell.first <= 9 && cell.second >= 0 && cell.second <= 9) {
                    shipBattleFieldSprite.setMarkedCellTexture(cell.first, cell.second);
                }
            }
        }
    }
    shipBattleFieldSprite.drawBattleField(getMainWindow());
}

void Player1PlacementWindow::drawText() {
    for (auto text : shipsCount) {
        text->draw(getMainWindow());
    }
}

void Player1PlacementWindow::render() {
    drawSprites();
    drawButtons();
    drawBattleField();
    drawShip();
    drawText();

}
