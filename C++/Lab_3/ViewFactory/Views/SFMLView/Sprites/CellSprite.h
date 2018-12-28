//
// Created by Bayramov Nidjat on 21.12.18.
//

#ifndef LAB_3_CELLSPRITE_H
#define LAB_3_CELLSPRITE_H

#include "Sprite.h"

class CellSprite : public Sprite {
    private:
        sf::Texture sea_cell;
        sf::Texture ship_cell;
        sf::Texture forbidden_cell;
    public:
        CellSprite(const int &x, const int &y) : Sprite(x, y) {
            sea_cell.loadFromFile("../src/Background/sea_cell.png");
            ship_cell.loadFromFile("../src/Background/ship_cell.png");
            forbidden_cell.loadFromFile("../src/Background/forbidden_cell.png");
            setTexture(sea_cell);
        }

        void setSeaCellTexture() {
            setTexture(sea_cell);
        }

        void setShipCellTexture() {
            setTexture(ship_cell);
        }

        void setForbiddenCellTexture() {
            setTexture(forbidden_cell);
        }
};

#endif //LAB_3_CELLSPRITE_H
