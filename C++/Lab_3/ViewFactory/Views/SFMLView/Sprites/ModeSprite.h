//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_MODESPRITE_H
#define LAB_3_MODESPRITE_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class ModeSprite : public Sprite {
    public:
        ModeSprite(const int &x, const int &y) : Sprite(x, y) {
            setTexture("../src/Background/mode.png");
        }
};

#endif //LAB_3_MODESPRITE_H
