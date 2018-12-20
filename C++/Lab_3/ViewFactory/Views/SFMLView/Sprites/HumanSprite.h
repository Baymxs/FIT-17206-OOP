//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_HUMANSPRITE_H
#define LAB_3_HUMANSPRITE_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class HumanSprite : public Sprite {
    public:
        HumanSprite() = default;
        HumanSprite(const int &x, const int &y) : Sprite(x, y) {
                setTexture("../src/Players/human.png");
            }
};

#endif //LAB_3_HUMANSPRITE_H
