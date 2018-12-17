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
void MenuWindow::drawBackground() {
    getMainWindow()->draw(background_sprite);
    getMainWindow()->draw(battle_ship_logo_sprite);
    getMainWindow()->draw(mode_sprite);
}

void MenuWindow::drawButtons() {
    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "start") {
        startButton.setButtonSelectedTexture();
    } else {
        startButton.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "left_selection_button1") {
        leftSelectionButton1.setButtonSelectedTexture();
    } else {
        leftSelectionButton1.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "right_selection_button1") {
        rightSelectionButton1.setButtonSelectedTexture();
    } else {
        rightSelectionButton1.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "left_selection_button2") {
        leftSelectionButton2.setButtonSelectedTexture();
    } else {
        leftSelectionButton2.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "right_selection_button2") {
        rightSelectionButton2.setButtonSelectedTexture();
    } else {
        rightSelectionButton2.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "options") {
        optionsButton.setButtonSelectedTexture();
    } else {
        optionsButton.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "exit") {
        exitButton.setButtonSelectedTexture();
    } else {
        exitButton.setButtonNormalTexture();
    }

    startButton.draw(getMainWindow());
    leftSelectionButton1.draw(getMainWindow());
    rightSelectionButton1.draw(getMainWindow());
    leftSelectionButton2.draw(getMainWindow());
    rightSelectionButton2.draw(getMainWindow());
    optionsButton.draw(getMainWindow());
    exitButton.draw(getMainWindow());
}

void MenuWindow::drawPlayers() {
    playerSprite1.changeSprite(getBattleShipModel()->getBattleShipMenuModel().getPlayer1());
    playerSprite2.changeSprite(getBattleShipModel()->getBattleShipMenuModel().getPlayer2());

    playerSprite1.draw(getMainWindow());
    playerSprite2.draw(getMainWindow());
}

void MenuWindow::render() {
    drawBackground();
    drawButtons();
    drawPlayers();
}


