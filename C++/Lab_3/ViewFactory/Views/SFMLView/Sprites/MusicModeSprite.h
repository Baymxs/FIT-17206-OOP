//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_MUSICMODESPRITE_H
#define LAB_3_MUSICMODESPRITE_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class MusicModeSprite : public Sprite {
    public:
        MusicModeSprite(const int &x, const int &y) : Sprite(x, y) {
            setTexture("../src/Background/music.png");
        }
};

#endif //LAB_3_MUSICMODESPRITE_H
