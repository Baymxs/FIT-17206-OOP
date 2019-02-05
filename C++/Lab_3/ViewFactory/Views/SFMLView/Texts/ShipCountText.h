//
// Created by Bayramov Nidjat on 07.01.19.
//

#ifndef LAB_3_SHIPCOUNTTEXT_H
#define LAB_3_SHIPCOUNTTEXT_H

#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class ShipCountText {
    private:
    sf::Font font;
    sf::Text ship_count;

    int *_count;

    public:
        explicit ShipCountText(int *count, int x, int y) {
                font.loadFromFile("../src/Fonts/ubuntu.ttf");

                _count = count;

                ship_count.setFont(font);
                ship_count.setCharacterSize(24);
                ship_count.setFillColor(sf::Color::White);

                ship_count.setPosition(x, y);
        }

        void draw(sf::RenderWindow* window) {
            ship_count.setString("x" + std::to_string(*_count));

            window->draw(ship_count);
        }
};

#endif //LAB_3_SHIPCOUNTTEXT_H
