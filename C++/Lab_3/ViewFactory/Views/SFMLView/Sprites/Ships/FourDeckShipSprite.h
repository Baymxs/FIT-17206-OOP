//
// Created by Bayramov Nidjat on 06.01.19.
//

#ifndef LAB_3_FOURDECKSHIPSPRITE_H
#define LAB_3_FOURDECKSHIPSPRITE_H

#include "../Sprite.h"

class FourDeckShipSprite : public Sprite {
        sf::Texture texture;
    public:
        FourDeckShipSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Ships/four-deck_ship.png");
            setTexture(texture);
        }
};

#endif //LAB_3_FOURDECKSHIPSPRITE_H
