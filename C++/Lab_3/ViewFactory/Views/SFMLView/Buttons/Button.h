//
// Created by Bayramov Nidjat on 08.12.18.
//

#ifndef LAB_3_BUTTON_H
#define LAB_3_BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
    private:
        std::string button_name;
        sf::Texture button_normal_texture;
        sf::Texture button_selected_texture;
        sf::Sprite button_sprite;

    public:
        Button(const std::string &button_name, const int &x, const int &y) {
            this->button_name = button_name;
            getButtonSprite().setPosition(x, y);
        }

        const std::string &getButtonName() const {
            return button_name;
        }

        sf::Texture &getButtonNormalTexture() {
            return button_normal_texture;
        }

        sf::Texture &getButtonSelectedTexture() {
            return button_selected_texture;
        }

        void setButtonNormalTexture() {
            button_sprite.setTexture(button_normal_texture);
        }

        void setButtonSelectedTexture() {
            button_sprite.setTexture(button_selected_texture);
        }

        sf::Sprite &getButtonSprite() {
            return button_sprite;
        }

        void draw(sf::RenderWindow* window) {
            window->draw(getButtonSprite());
        };
};

#endif //LAB_3_BUTTON_H
