//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_BACKGROUNDSPRITE_H
#define LAB_3_BACKGROUNDSPRITE_H

#include "Sprite.h"

class BackgroundSprite : public Sprite {
    sf::Texture texture;
    public:
        BackgroundSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Background/background.jpg");
            setTexture(texture);
        }
};

#endif //LAB_3_BACKGROUNDSPRITE_H
