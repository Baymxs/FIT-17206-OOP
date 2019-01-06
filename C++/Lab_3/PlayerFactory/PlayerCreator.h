//
// Created by Bayramov Nidjat on 28.12.18.
//

#ifndef LAB_3_PLAYERCREATOR_H
#define LAB_3_PLAYERCREATOR_H

#include "Player.h"

//Interface
//We can't create an object of type PlayerCreator
//Class PlayerCreator do not have properties
//The methods of class PlayerCreator have no defined methods bodies
class PlayerCreator {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method create() because = 0 means that virtual method
        //create() has no body in class PlayerCreator
        virtual Player* create(BattleShipModel *battleShipModel) = 0;
};

#endif //LAB_3_PLAYERCREATOR_H
