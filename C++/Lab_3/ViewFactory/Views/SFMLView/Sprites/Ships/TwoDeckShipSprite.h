//
// Created by Bayramov Nidjat on 06.01.19.
//

#ifndef LAB_3_TWODECKSHIPSPRITE_H
#define LAB_3_TWODECKSHIPSPRITE_H

#include "../Sprite.h"

class TwoDeckShipSprite : public Sprite {
        sf::Texture texture;
    public:
        TwoDeckShipSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Ships/two-deck_ship.png");
            setTexture(texture);
        }
};

#endif //LAB_3_TWODECKSHIPSPRITE_H
