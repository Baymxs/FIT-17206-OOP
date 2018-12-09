//
// Created by Bayramov Nidjat on 17.11.18.
//

#ifndef LAB_3_VIEWCREATOR_H
#define LAB_3_VIEWCREATOR_H

#include "View.h"

//Interface
//We can't create an object of type ViewCreator
//Class ViewCreator do not have properties
//The methods of class ViewCreator have no defined methods bodies
class ViewCreator {
    public:
        //Pure virtual function
        //Every child-class MUST have it's own version of the method create() because = 0 means that virtual method
        //create() has no body in class ViewCreator
        virtual View* create() = 0;
};
#endif //LAB_3_VIEWCREATOR_H
