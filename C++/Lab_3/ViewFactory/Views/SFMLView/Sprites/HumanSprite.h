//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_HUMANSPRITE_H
#define LAB_3_HUMANSPRITE_H

#include "Sprite.h"

class HumanSprite : public Sprite {
    sf::Texture texture;
    public:
        HumanSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Players/human.png");
            setTexture(texture);
            }
};

#endif //LAB_3_HUMANSPRITE_H
