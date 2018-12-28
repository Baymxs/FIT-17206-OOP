//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_EASYBOTSPRITE_H
#define LAB_3_EASYBOTSPRITE_H

#include "Sprite.h"

class EasyBotSprite : public Sprite {
    sf::Texture texture;
    public:
        EasyBotSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Players/easy_bot.png");
            setTexture(texture);
        }
};

#endif //LAB_3_EASYBOTSPRITE_H
