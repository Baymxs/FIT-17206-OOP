//
// Created by Bayramov Nidjat on 08.12.18.
//

#ifndef LAB_3_BUTTON_H
#define LAB_3_BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
    private:
        sf::Texture button_texture;
        sf::Sprite button_sprite;
    public:
        sf::Texture &getButtonTexture() {
            return button_texture;
        }

        sf::Sprite &getButtonSprite(){
            return button_sprite;
        }

        void draw(sf::RenderWindow* main_window) {
            main_window->draw(getButtonSprite());
        };
};

#endif //LAB_3_BUTTON_H
