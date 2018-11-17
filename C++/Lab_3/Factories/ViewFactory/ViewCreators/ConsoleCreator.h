//
// Created by Bayramov Nidjat on 17.11.18.
//

#ifndef LAB_3_CONSOLECREATOR_H
#define LAB_3_CONSOLECREATOR_H

#include "../ViewCreator.h"
#include "../View.h"
#include "../Views/ConsoleView.h"

class ConsoleCreator : public ViewCreator {
    View* create() override {
        return new ConsoleView();
    }
};

#endif //LAB_3_CONSOLECREATOR_H
