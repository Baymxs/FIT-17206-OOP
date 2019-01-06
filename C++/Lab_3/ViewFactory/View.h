//
// Created by Bayramov Nidjat on 17.11.18.
//

#ifndef LAB_3_VIEW_H
#define LAB_3_VIEW_H

#include "../BattleShipModel.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class View {
    private:
        BattleShipModel *battleShipModel;
    public:
        explicit View(BattleShipModel *battleShipModel) {
                this->battleShipModel = battleShipModel;
        }

        BattleShipModel *getBattleShipModel() {
                return battleShipModel;
        }

        //Pure virtual function
        //Every child-class MUST have it's own version of the method display() because = 0 means that virtual method
        //render() has no body in class View
        virtual void render() = 0;
        virtual sf::RenderWindow* getMainWindow() = 0;
};

#endif //LAB_3_VIEW_H
