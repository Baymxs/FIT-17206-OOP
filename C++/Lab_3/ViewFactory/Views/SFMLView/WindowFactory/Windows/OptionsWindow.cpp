//
// Created by Bayramov Nidjat on 16.12.18.
//

#include "OptionsWindow.h"
#include "../WindowFactory.h"
#include "../WindowCreators/OptionsCreator.h"


//Initialize the window before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeOptionsWindow() {
        WindowFactory::getInstance().registerWindows("Options", new OptionsCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeOptionsWindow();
}

void OptionsWindow::drawSprites() {
    for (auto sprite : sprites) {
        sprite->draw(getMainWindow());
    }
}

void OptionsWindow::drawButtons() {
    for (auto button : buttons) {
        if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == button->getButtonName()) {
            button->setButtonSelectedTexture();
        } else {
            button->setButtonNormalTexture();
        }
        button->draw(getMainWindow());
    }
}

void OptionsWindow::drawVolume() {
    volumeSprite.changeSprite(getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection());
    volumeSprite.draw(getMainWindow());
}

void OptionsWindow::render() {
    drawSprites();
    drawButtons();
    drawVolume();
}

