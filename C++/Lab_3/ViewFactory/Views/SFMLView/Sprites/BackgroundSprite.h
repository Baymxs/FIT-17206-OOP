//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_BACKGROUNDSPRITE_H
#define LAB_3_BACKGROUNDSPRITE_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class BackgroundSprite : public Sprite {
    public:
        BackgroundSprite(const int &x, const int &y) : Sprite(x, y) {
            setTexture("../src/Background/background.jpg");
        }
};

#endif //LAB_3_BACKGROUNDSPRITE_H
