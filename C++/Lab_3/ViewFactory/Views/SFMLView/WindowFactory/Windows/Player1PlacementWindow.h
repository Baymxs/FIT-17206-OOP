//
// Created by Bayramov Nidjat on 31.12.18.
//

#ifndef LAB_3_PLAYER1PLACEMENTWINDOW_H
#define LAB_3_PLAYER1PLACEMENTWINDOW_H

#include "../Window.h"
#include "../../Sprites/Sprite.h"
#include "../../Sprites/BackgroundSprite.h"
#include "../../PlayerSprite.h"
#include "../../Buttons/Button.h"
#include "../../Buttons/BackButton.h"
#include "../../Sprites/BattleFieldSprite.h"
#include "../../PlayerSprite.h"
#include "../../Buttons/NextButton.h"

class Player1PlacementWindow : public Window {
    private:
        std::vector<Sprite*> sprites {new BackgroundSprite(0, 0)};
        PlayerSprite playerSprite{getBattleShipModel()->getPlayer1(), 20, 22};
        std::vector<Button*> buttons {new BackButton("back", 10, 540), new NextButton("next", 624, 540)};

        BattleFieldSprite battleFieldSprite{293, 80};
        BattleFieldSprite shipBattleFieldSprite{293, 80};

        void drawSprites();
        void drawButtons();
        void drawBattleField();
        void drawShip();
    public:
        explicit Player1PlacementWindow(BattleShipModel *battleShipModel) : Window(battleShipModel) {}
        void render() override;
};


#endif //LAB_3_PLAYER1PLACEMENTWINDOW_H
