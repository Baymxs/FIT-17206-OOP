//
// Created by Bayramov Nidjat on 29.11.18.
//

#ifndef LAB_3_CONTROLLER_H
#define LAB_3_CONTROLLER_H

#include <SFML/Graphics.hpp>

//Interface
//We can't create an object of type Controller
//Class Controller do not have properties
//The methods of class Controller have no defined methods bodies
class Controller {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method handleEvent() because = 0 means that virtual method
        //handleEvent() has no body in class Controller
        virtual void handleEvent(sf::Event event) = 0;
};

#endif //LAB_3_CONTROLLER_H
