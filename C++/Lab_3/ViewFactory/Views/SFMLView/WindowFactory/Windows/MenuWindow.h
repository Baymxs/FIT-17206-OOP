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
#include "../../Sprites/BackgroundSprite.h"
#include "../../Sprites/LogoSprite.h"
#include "../../Sprites/ModeSprite.h"
#include "../../PlayerSprite.h"

class MenuWindow : public Window {
    private:
        std::vector<Sprite*> sprites {new BackgroundSprite(0, 0), new LogoSprite(104, 55), new ModeSprite(292, 274)};

        std::vector<Button*> buttons {new StartButton("start", 275, 200),
                                      new LeftSelectionButton("left_selection_button1", 60, 349), new RightSelectionButton("right_selection_button1", 335, 349),
                                      new LeftSelectionButton("left_selection_button2", 400, 349), new RightSelectionButton("right_selection_button2", 675, 349),
                                      new OptionsButton("options", 245, 424),
                                      new ExitButton("exit", 309, 496)};

        PlayerSprite playerSprite1{"player_selection1"};
        PlayerSprite playerSprite2{"player_selection2"};

        void drawSprites();
        void drawButtons();
        void drawPlayers();
    public:
        explicit MenuWindow(BattleShipModel *battleShipModel) : Window(battleShipModel) {}
        virtual ~MenuWindow();

        void render() override;
};

#endif //LAB_3_MENUWINDOW_H
