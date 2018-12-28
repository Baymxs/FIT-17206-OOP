//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_HARDBOTSPRITE_H
#define LAB_3_HARDBOTSPRITE_H

#include "Sprite.h"

class HardBotSprite : public Sprite {
    sf::Texture texture;
    public:
        HardBotSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Players/hard_bot.png");
            setTexture(texture);
        }
};

#endif //LAB_3_HARDBOTSPRITE_H
