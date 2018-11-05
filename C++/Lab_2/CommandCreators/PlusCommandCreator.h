//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_PLUSCOMMANDCREATOR_H
#define LAB_2_PLUSCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/PlusCommand.h"

class PlusCommandCreator : public CommandCreator {
    Command* create() override {
        return new PlusCommand();
    }
};

#endif //LAB_2_PLUSCOMMANDCREATOR_H