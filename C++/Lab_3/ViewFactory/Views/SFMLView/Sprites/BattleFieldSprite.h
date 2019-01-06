//
// Created by Bayramov Nidjat on 21.12.18.
//

#ifndef LAB_3_BATTLEFIELDSPRITE_H
#define LAB_3_BATTLEFIELDSPRITE_H

#include "CellSprite.h"

class BattleFieldSprite {
    private:
        std::vector<CellSprite*> battle_filed;
    public:
        BattleFieldSprite(int x, int y) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    battle_filed.push_back(new CellSprite(x + (42 * j), y + (42 * i)));
                }
            }
        }

        void drawBattleField(sf::RenderWindow *window) {
            for (auto cellSprite : battle_filed) {
                cellSprite->draw(window);
            }
        }

        void setMarkedCellTexture(int i, int j) {
            if (i >= 0 && j >= 0) {
                battle_filed[10 * j + i]->setMarkedCellTexture();
            }
        }

        void setShipCellTexture(int i, int j) {
            battle_filed[10*j + i]->setShipCellTexture();
        }

        void setForbiddenCellTexture(int i, int j) {
            battle_filed[10*j + i]->setForbiddenCellTexture();
        }

        void setTransparentCellTexture(int i, int j) {
            battle_filed[10*j + i]->setTransparentCellTexture();
        }

};

#endif //LAB_3_BATTLEFIELDSPRITE_H
