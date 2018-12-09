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
    sf::Texture background_texture;
    background_texture.loadFromFile("../src/Background/menu_background.jpg");

    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);

    sf::Texture battle_ship_logo_texture;
    battle_ship_logo_texture.loadFromFile("../src/Background/battle_ship_logo.png");

    sf::Sprite battle_ship_logo_sprite;
    battle_ship_logo_sprite.setTexture(battle_ship_logo_texture);
    battle_ship_logo_sprite.setPosition(104, 55);

    sf::Texture mode_texture;
    mode_texture.loadFromFile("../src/Background/mode.png");

    sf::Sprite mode_sprite;
    mode_sprite.setTexture(mode_texture);
    mode_sprite.setPosition(292, 274);

    getMainWindow()->draw(background_sprite);
    getMainWindow()->draw(battle_ship_logo_sprite);
    getMainWindow()->draw(mode_sprite);
}

void MenuWindow::drawButtons() {
    startButton.draw(getMainWindow());
    optionsButton.draw(getMainWindow());
    leftModeSelectionButton1.draw(getMainWindow());
    rightModeSelectionButton1.draw(getMainWindow());
    leftModeSelectionButton2.draw(getMainWindow());
    rightModeSelectionButton2.draw(getMainWindow());

}

void MenuWindow::render(BattleShipModel *battleShipModel) {
    drawBackground();
    drawButtons();
}

