//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_COMMANDCREATOR_H
#define LAB_2_COMMANDCREATOR_H

#include "Command.h"

//Interface
//We can't create an object of type CommandCreator
//Class CommandCreator do not have properties
//The methods of class CommandCreator have no defined methods bodies
class CommandCreator {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method create() because = 0 means that virtual method
        //create() has no body in class CommandCreator
        virtual Command* create() = 0;
};

#endif //LAB_2_COMMANDCREATOR_H
