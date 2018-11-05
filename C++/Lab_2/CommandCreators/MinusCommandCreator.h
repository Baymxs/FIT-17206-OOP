//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_MINUSCOMMANDCREATOR_H
#define LAB_2_MINUSCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/MinusCommand.h"

class MinusCommandCreator : public CommandCreator{
    Command* create() override {
        return new MinusCommand();
    }
};

#endif //LAB_2_MINUSCOMMANDCREATOR_H