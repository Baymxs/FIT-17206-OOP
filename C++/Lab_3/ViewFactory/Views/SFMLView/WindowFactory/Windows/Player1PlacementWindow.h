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
#include "../../Sprites/Ships/OneDeckShipSprite.h"
#include "../../Sprites/Ships/TwoDeckShipSprite.h"
#include "../../Sprites/Ships/ThreeDeckShipSprite.h"
#include "../../Sprites/Ships/FourDeckShipSprite.h"
#include "../../Buttons/RandomButton.h"
#include "../../Texts/ShipCountText.h"

class Player1PlacementWindow : public Window {
    private:
        PlayerSprite playerSprite{getBattleShipModel()->getPlayer1(), 20, 22};

        std::vector<Sprite*> sprites {new BackgroundSprite(0, 0),
                                      new OneDeckShipSprite(53, 80),
                                      new TwoDeckShipSprite(53, 130),
                                      new ThreeDeckShipSprite(53, 180),
                                      new FourDeckShipSprite(53, 230)};

        std::vector<ShipCountText*> shipsCount {new ShipCountText{&getBattleShipModel()->getShipsCount()[0], 107, 87},
                                           new ShipCountText{&getBattleShipModel()->getShipsCount()[1], 147, 137},
                                           new ShipCountText{&getBattleShipModel()->getShipsCount()[2], 191, 187},
                                           new ShipCountText{&getBattleShipModel()->getShipsCount()[3], 233, 237}};

        std::vector<Button*> buttons {new BackButton("back", 10, 540),
                                      new NextButton("next", 624, 540),
                                      new RandomButton("random", 26, 285)};

        BattleFieldSprite battleFieldSprite{293, 80};
        BattleFieldSprite shipBattleFieldSprite{293, 80};

        void drawSprites();
        void drawButtons();
        void drawBattleField();
        void drawShip();
        void drawText();
    public:
        explicit Player1PlacementWindow(BattleShipModel *battleShipModel) : Window(battleShipModel) {}
        void render() override;
};


#endif //LAB_3_PLAYER1PLACEMENTWINDOW_H
