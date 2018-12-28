//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_SPRITE_H
#define LAB_3_SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite {
   private:
        sf::Sprite sprite;
   public:
        Sprite() = default;
        Sprite(const int &x, const int &y) {
                sprite.setPosition(x, y);
        }

        void setTexture(const sf::Texture &texture) {
            sprite.setTexture(texture);
        }

        void draw(sf::RenderWindow* window) {
                window->draw(sprite);
        }
};
#endif //LAB_3_SPRITE_H
