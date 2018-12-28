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
        BattleFieldSprite() {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    battle_filed.push_back(new CellSprite(197 + (42 * j), 80 + (42 * i)));
                }
            }
        }

        void drawBattleField(sf::RenderWindow *window) {
            for (auto cellSprite : battle_filed) {
                cellSprite->draw(window);
            }
        }

        void setSeaCellTexture(int i, int j) {
            battle_filed[10*j + i]->setSeaCellTexture();
        }

        void setShipCellTexture(int i, int j) {
            battle_filed[10*j + i]->setShipCellTexture();
        }

        void setForbiddenCellTexture(int i, int j) {
            battle_filed[10*j + i]->setForbiddenCellTexture();
        }

};

#endif //LAB_3_BATTLEFIELDSPRITE_H
