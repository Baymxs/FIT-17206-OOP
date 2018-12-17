//
// Created by Bayramov Nidjat on 16.12.18.
//

#ifndef LAB_3_VOLUMESPRITE_H
#define LAB_3_VOLUMESPRITE_H

#include <SFML/Graphics.hpp>

class VolumeSprite {
    private:
        sf::Sprite volume_sprite;
        sf::Texture volume_on_texture;
        sf::Texture volume_off_texture;
    public:
        explicit VolumeSprite() {
            volume_on_texture.loadFromFile("../src/Volumes/on.png");
            volume_off_texture.loadFromFile("../src/Volumes/off.png");
        }

    void changeSprite(int volume_state) {
        if (volume_state == 1) {
            volume_sprite.setTexture(volume_on_texture);
            volume_sprite.setPosition(348, 216);
        } else if (volume_state == 2) {
            volume_sprite.setTexture(volume_off_texture);
            volume_sprite.setPosition(338, 216);
        }
    }

    void draw(sf::RenderWindow *main_window) {
        main_window->draw(volume_sprite);
    }
};
#endif //LAB_3_VOLUMESPRITE_H
