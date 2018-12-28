//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_MODESPRITE_H
#define LAB_3_MODESPRITE_H

#include "Sprite.h"

class ModeSprite : public Sprite {
    sf::Texture texture;
    public:
        ModeSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Background/mode.png");
            setTexture(texture);
        }
};

#endif //LAB_3_MODESPRITE_H
