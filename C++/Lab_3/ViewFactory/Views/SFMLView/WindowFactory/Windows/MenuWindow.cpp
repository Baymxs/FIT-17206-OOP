//
// Created by Bayramov Nidjat on 21.11.18.
//
#include "MenuWindow.h"
#include "../WindowFactory.h"
#include "../WindowCreators/MenuCreator.h"

#include <SFML/Graphics.hpp>

//Initialize the window before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeMenuWindow() {
        WindowFactory::getInstance().registerWindows("Menu", new MenuCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeMenuWindow();
}

void MenuWindow::drawSprites() {
    for (auto sprite : sprites) {
        sprite->draw(getMainWindow());
    }
}

void MenuWindow::drawButtons() {
    for (int i = 0; i < buttons.size(); i++) {
        if (getBattleShipModel()->isGameStarted() && (i == 1 || i == 2 || i == 3 || i == 4)) {
            buttons[i]->setButtonInvisibleTexture();
        } else if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == buttons[i]->getButtonName()) {
            buttons[i]->setButtonSelectedTexture();
        } else {
            buttons[i]->setButtonNormalTexture();
        }
        buttons[i]->draw(getMainWindow());
    }
}

void MenuWindow::drawPlayers() {
    playerSprite1.changeSprite(getBattleShipModel()->getPlayer1());
    playerSprite2.changeSprite(getBattleShipModel()->getPlayer2());

    playerSprite1.draw(getMainWindow());
    playerSprite2.draw(getMainWindow());
}

void MenuWindow::render() {
    drawSprites();
    drawButtons();
    drawPlayers();
}

MenuWindow::~MenuWindow() {
    for (auto sprite : sprites) {
        free(sprite);
    }
    for (auto button : buttons) {
        free(button);
    }
}


