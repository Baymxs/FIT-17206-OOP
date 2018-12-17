//
// Created by Bayramov Nidjat on 29.11.18.
//

#ifndef LAB_3_CONTROLLERCREATOR_H
#define LAB_3_CONTROLLERCREATOR_H

#include "Controller.h"

//Interface
//We can't create an object of type ControllerCreator
//Class ControllerCreator do not have properties
//The methods of class ControllerCreator have no defined methods bodies
class ControllerCreator {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method create() because = 0 means that virtual method
        //create() has no body in class ControllerCreator
        virtual Controller* create(BattleShipModel *battleShipModel) = 0;
};

#endif //LAB_3_CONTROLLERCREATOR_H
