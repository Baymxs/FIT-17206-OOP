//
// Created by Bayramov Nidjat on 06.01.19.
//

#ifndef LAB_3_ONEDECKSHIPSPRITE_H
#define LAB_3_ONEDECKSHIPSPRITE_H

#include "../Sprite.h"

class OneDeckShipSprite : public Sprite {
        sf::Texture texture;
    public:
        OneDeckShipSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Ships/one-deck_ship.png");
            setTexture(texture);
        }
};

#endif //LAB_3_ONEDECKSHIPSPRITE_H
