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
    for (auto button : buttons) {
        if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == button->getButtonName()) {
            button->setButtonSelectedTexture();
        } else {
            button->setButtonNormalTexture();
        }
        button->draw(getMainWindow());
    }
}

void MenuWindow::drawPlayers() {
    playerSprite1.changeSprite(getBattleShipModel()->getBattleShipMenuModel().getPlayer1());
    playerSprite2.changeSprite(getBattleShipModel()->getBattleShipMenuModel().getPlayer2());

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


