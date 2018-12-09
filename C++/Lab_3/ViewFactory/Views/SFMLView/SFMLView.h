//
// Created by Bayramov Nidjat on 28.11.18.
//

#ifndef LAB_3_SFMLVIEW_H
#define LAB_3_SFMLVIEW_H

#include "../../View.h"
#include "WindowFactory/Window.h"
#include "../../../BattleShipModel.h"

#include <SFML/Graphics.hpp>

class SFMLView : public View {
    private:
        Window *window = nullptr;
        sf::RenderWindow main_window;
    public:
        SFMLView() {
            main_window.create(sf::VideoMode(800, 600), "BattleShip", sf::Style::Titlebar | sf::Style::Close);
        }
        sf::RenderWindow* getMainWindow() override {
            return &main_window;
        };
        void render(BattleShipModel*) override;
};


#endif //LAB_3_SFMLVIEW_H
