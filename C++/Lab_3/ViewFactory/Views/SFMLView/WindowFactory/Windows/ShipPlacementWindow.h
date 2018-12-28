//
// Created by Bayramov Nidjat on 21.12.18.
//

#ifndef LAB_3_SHIPPLACEMENTWINDOW_H
#define LAB_3_SHIPPLACEMENTWINDOW_H

#include "../Window.h"
#include "../../Sprites/Sprite.h"
#include "../../Sprites/BackgroundSprite.h"
#include "../../Buttons/Button.h"
#include "../../Buttons/BackButton.h"
#include "../../Sprites/BattleFieldSprite.h"
#include "../../PlayerSprite.h"

class ShipPlacementWindow : public Window {
    private:
        std::vector<Sprite*> sprites {new BackgroundSprite(0, 0)};
        std::vector<Button*> buttons {new BackButton("back", 10, 540)};

        BattleFieldSprite battleFieldSprite;
        BattleFieldSprite shipSprite;

        void drawSprites();
        void drawPlayers();
        void drawButtons();
        void drawBattleField();
        void drawShip();
    public:
        explicit ShipPlacementWindow(BattleShipModel *battleShipModel) : Window(battleShipModel) {}
        void render() override;
};

#endif //LAB_3_SHIPPLACEMENTWINDOW_H
