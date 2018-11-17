//
// Created by Bayramov Nidjat on 17.11.18.
//

#ifndef LAB_3_VIEW_H
#define LAB_3_VIEW_H

#include <vector>

//Interface
//We can't create an object of type Command
//Class Command do not have properties
//The methods of class Command have no defined methods bodies
class View {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method execute() because = 0 means that virtual method
        //execute() has no body in class View
        virtual void execute(std::vector<std::string>) = 0;
};

#endif //LAB_3_VIEW_H
