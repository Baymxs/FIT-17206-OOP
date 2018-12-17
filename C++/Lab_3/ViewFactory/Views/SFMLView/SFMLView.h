//
// Created by Bayramov Nidjat on 28.11.18.
//

#ifndef LAB_3_SFMLVIEW_H
#define LAB_3_SFMLVIEW_H

#include "../../View.h"
#include "WindowFactory/Window.h"
#include "../../../BattleShipModel.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SFMLView : public View {
    private:
        Window *window = nullptr;
        sf::RenderWindow main_window;
        sf::SoundBuffer buffer;
        sf::Sound sound;
    public:
        explicit SFMLView(BattleShipModel *battleShipModel) : View(battleShipModel) {
            main_window.create(sf::VideoMode(800, 600), "BattleShip", sf::Style::Titlebar | sf::Style::Close);
            main_window.setFramerateLimit(120);

            buffer.loadFromFile("../src/Music/Pirates.wav");

            sound.setBuffer(buffer);
            sound.setLoop(true);
            sound.play();
        }
        sf::RenderWindow* getMainWindow() override {
            return &main_window;
        };

        void render() override;
};


#endif //LAB_3_SFMLVIEW_H
