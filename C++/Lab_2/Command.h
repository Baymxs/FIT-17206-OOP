//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_COMMAND_H
#define LAB_2_COMMAND_H

#include <vector>
#include <string>

//Interface
//We can't create an object of type Command
//Class Command do not have properties
//The methods of class Command have no defined methods bodies
class Command {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method execute() because = 0 means that virtual method
        //execute() has no body in class Command
        virtual void execute(std::vector<std::string>) = 0;
};


#endif //LAB_2_COMMAND_H
