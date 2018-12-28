//
// Created by Bayramov Nidjat on 12.12.18.
//

#ifndef LAB_3_PLAYERSPRITE_H
#define LAB_3_PLAYERSPRITE_H

#include <SFML/Graphics.hpp>

class PlayerSprite {
    private:
        sf::Sprite player_sprite;
        sf::Texture human_texture;
        sf::Texture easy_bot_texture;
        sf::Texture hard_bot_texture;

        std::string player_selection;
    public:
        explicit PlayerSprite(const std::string &player_selection) {
            this->player_selection = player_selection;
            human_texture.loadFromFile("../src/Players/human.png");
            easy_bot_texture.loadFromFile("../src/Players/easy_bot.png");
            hard_bot_texture.loadFromFile("../src/Players/hard_bot.png");
        }

        void changeSprite(int player_number) {
            if (player_selection == "player_selection1") {
                if (player_number == 1) {
                    player_sprite.setTexture(human_texture);
                    player_sprite.setPosition(150, 362);
                }
                if (player_number == 2) {
                    player_sprite.setTexture(easy_bot_texture);
                    player_sprite.setPosition(122, 362);
                }
                if (player_number == 3) {
                    player_sprite.setTexture(hard_bot_texture);
                    player_sprite.setPosition(122, 362);
                }
            }

            if (player_selection == "player_selection2") {
                if (player_number == 1) {
                    player_sprite.setTexture(human_texture);
                    player_sprite.setPosition(490, 362);
                }
                if (player_number == 2) {
                    player_sprite.setTexture(easy_bot_texture);
                    player_sprite.setPosition(462, 362);
                }
                if (player_number == 3) {
                    player_sprite.setTexture(hard_bot_texture);
                    player_sprite.setPosition(462, 362);
                }
            }
        }

        void draw(sf::RenderWindow *main_window) {
            main_window->draw(player_sprite);
        }
};

#endif //LAB_3_PLAYERSPRITE_H
