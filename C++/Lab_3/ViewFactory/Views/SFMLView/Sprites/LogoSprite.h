//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_LOGOSPRITE_H
#define LAB_3_LOGOSPRITE_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class LogoSprite : public Sprite {
    public:
        LogoSprite(const int &x, const int &y) : Sprite(x, y) {
            setTexture("../src/Background/logo.png");
        }
};

#endif //LAB_3_LOGOSPRITE_H
