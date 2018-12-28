//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_LOGOSPRITE_H
#define LAB_3_LOGOSPRITE_H

#include "Sprite.h"

class LogoSprite : public Sprite {
    sf::Texture texture;
    public:
        LogoSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Background/logo.png");
            setTexture(texture);
        }
};

#endif //LAB_3_LOGOSPRITE_H
