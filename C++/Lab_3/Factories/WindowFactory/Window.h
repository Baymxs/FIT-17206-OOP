//
// Created by Bayramov Nidjat on 21.11.18.
//

#ifndef LAB_3_WINDOW_H
#define LAB_3_WINDOW_H

//Interface
//We can't create an object of type Window
//Class Window do not have properties
//The methods of class Window have no defined methods bodies
class Window {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the methods because = 0 means that virtual methods
        //have no bodies in class View
        virtual void execute() = 0;
};

#endif //LAB_3_WINDOW_H
