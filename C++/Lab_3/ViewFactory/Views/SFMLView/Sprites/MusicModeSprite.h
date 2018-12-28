//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_MUSICMODESPRITE_H
#define LAB_3_MUSICMODESPRITE_H

#include "Sprite.h"

class MusicModeSprite : public Sprite {
    sf::Texture texture;
    public:
        MusicModeSprite(const int &x, const int &y) : Sprite(x, y) {
            texture.loadFromFile("../src/Background/music.png");
            setTexture(texture);
        }
};

#endif //LAB_3_MUSICMODESPRITE_H
