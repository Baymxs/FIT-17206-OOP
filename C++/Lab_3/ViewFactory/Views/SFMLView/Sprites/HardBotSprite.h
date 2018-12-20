//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_HARDBOTSPRITE_H
#define LAB_3_HARDBOTSPRITE_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class HardBotSprite : public Sprite {
    public:
        HardBotSprite() = default;
        HardBotSprite(const int &x, const int &y) : Sprite(x, y) {
                setTexture("../src/Players/hard_bot.png");
            }
};

#endif //LAB_3_HARDBOTSPRITE_H
