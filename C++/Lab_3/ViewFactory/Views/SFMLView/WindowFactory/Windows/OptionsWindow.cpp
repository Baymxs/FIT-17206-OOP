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

void OptionsWindow::drawBackground() {
    getMainWindow()->draw(background_sprite);
    getMainWindow()->draw(music_sprite);
}

void OptionsWindow::drawButtons() {
    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "left_selection_button") {
        leftSelectionButton.setButtonSelectedTexture();
    } else {
        leftSelectionButton.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "right_selection_button") {
        rightSelectionButton.setButtonSelectedTexture();
    } else {
        rightSelectionButton.setButtonNormalTexture();
    }

    if (getBattleShipModel()->getBattleShipMenuModel().getMenuMove() == "back_button") {
        backButton.setButtonSelectedTexture();
    } else {
        backButton.setButtonNormalTexture();
    }

    leftSelectionButton.draw(getMainWindow());
    rightSelectionButton.draw(getMainWindow());
    backButton.draw(getMainWindow());
}

void OptionsWindow::drawVolume() {
    volumeSprite.changeSprite(getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection());

    volumeSprite.draw(getMainWindow());
}

void OptionsWindow::render() {
    drawBackground();
    drawButtons();
    drawVolume();
}

