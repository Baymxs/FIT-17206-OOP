//
// Created by Bayramov Nidjat on 17.11.18.
//

#ifndef LAB_3_VIEW_H
#define LAB_3_VIEW_H

#include "../BattleShipModel.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

//Interface
//We can't create an object of type View
//Class View do not have properties
//The methods of class View have no defined methods bodies
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
        //display() has no body in class View
        virtual void render() = 0;
        virtual sf::RenderWindow* getMainWindow() = 0;
};

#endif //LAB_3_VIEW_H
