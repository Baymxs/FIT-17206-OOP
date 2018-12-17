//
// Created by Bayramov Nidjat on 21.11.18.
//

#ifndef LAB_3_MENUWINDOW_H
#define LAB_3_MENUWINDOW_H


#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "../Window.h"
#include "../../Buttons/StartButton.h"
#include "../../Buttons/OptionsButton.h"
#include "../../Buttons/LeftSelectionButton.h"
#include "../../Buttons/RightSelectionButton.h"
#include "../../Buttons/ExitButton.h"
#include "../../PlayerSprite.h"

class MenuWindow : public Window {
    private:
        sf::Sprite background_sprite;
        sf::Sprite battle_ship_logo_sprite;
        sf::Sprite mode_sprite;

        StartButton startButton{275, 200};
        LeftSelectionButton leftSelectionButton1{60, 349};
        RightSelectionButton rightSelectionButton1{335, 349};
        LeftSelectionButton leftSelectionButton2{400, 349};
        RightSelectionButton rightSelectionButton2{675, 349};
        OptionsButton optionsButton{245, 424};
        ExitButton exitButton{309, 496};

        PlayerSprite playerSprite1{"player_selection1"};
        PlayerSprite playerSprite2{"player_selection2"};

        void drawBackground();
        void drawButtons();
        void drawPlayers();
    public:
        explicit MenuWindow(BattleShipModel *battleShipModel) : Window(battleShipModel) {
            static sf::Texture background_texture;
            background_texture.loadFromFile("../src/Background/menu_background.jpg");
            background_sprite.setTexture(background_texture);

            static  sf::Texture battle_ship_logo_texture;
            battle_ship_logo_texture.loadFromFile("../src/Background/battle_ship_logo.png");
            battle_ship_logo_sprite.setTexture(battle_ship_logo_texture);
            battle_ship_logo_sprite.setPosition(104, 55);

            static sf::Texture mode_texture;
            mode_texture.loadFromFile("../src/Background/mode.png");
            mode_sprite.setTexture(mode_texture);
            mode_sprite.setPosition(292, 274);
        }

        void render() override;
};

#endif //LAB_3_MENUWINDOW_H
