//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_EASYBOTSPRITE_H
#define LAB_3_EASYBOTSPRITE_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class EasyBotSprite : public Sprite {
    public:
        EasyBotSprite() = default;
        EasyBotSprite(const int &x, const int &y) : Sprite(x, y) {
            setTexture("../src/Players/easy_bot.png");
        }
};

#endif //LAB_3_EASYBOTSPRITE_H
