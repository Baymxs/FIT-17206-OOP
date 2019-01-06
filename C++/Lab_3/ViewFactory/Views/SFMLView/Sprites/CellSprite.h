//
// Created by Bayramov Nidjat on 21.12.18.
//

#ifndef LAB_3_CELLSPRITE_H
#define LAB_3_CELLSPRITE_H

#include "Sprite.h"

class CellSprite : public Sprite {
    private:
        sf::Texture ship_cell;
        sf::Texture marked_cell;
        sf::Texture forbidden_cell;
        sf::Texture transparent_cell;
    public:
        CellSprite(const int &x, const int &y) : Sprite(x, y) {
            ship_cell.loadFromFile("../src/Background/ship_cell.png");
            marked_cell.loadFromFile("../src/Background/marked_cell.png");
            forbidden_cell.loadFromFile("../src/Background/forbidden_cell.png");
            transparent_cell.loadFromFile("../src/Background/transparent_cell.png");
        }

        void setMarkedCellTexture() {
            setTexture(marked_cell);
        }

        void setShipCellTexture() {
            setTexture(ship_cell);
        }

        void setForbiddenCellTexture() {
            setTexture(forbidden_cell);
        }

        void setTransparentCellTexture() {
            setTexture(transparent_cell);
        }
};

#endif //LAB_3_CELLSPRITE_H
