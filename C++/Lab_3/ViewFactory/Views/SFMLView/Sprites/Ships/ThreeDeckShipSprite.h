//
// Created by Bayramov Nidjat on 06.01.19.
//

#ifndef LAB_3_THREEDECKSHIPSPRITE_H
#define LAB_3_THREEDECKSHIPSPRITE_H

#include "../Sprite.h"

class ThreeDeckShipSprite : public Sprite {
        sf::Texture texture;
    public:
        ThreeDeckShipSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Ships/three-deck_ship.png");
            setTexture(texture);
        }
};

#endif //LAB_3_THREEDECKSHIPSPRITE_H
