//
// Created by Bayramov Nidjat on 21.11.18.
//

#ifndef LAB_3_WINDOWCREATOR_H
#define LAB_3_WINDOWCREATOR_H

#include "Window.h"

//Interface
//We can't create an object of type WindowCreator
//Class WindowCreator do not have properties
//The methods of class WindowCreator have no defined methods bodies
class WindowCreator {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method create() because = 0 means that virtual method
        //create() has no body in class WindowCreator
        virtual Window* create() = 0;
};

#endif //LAB_3_WINDOWCREATOR_H
