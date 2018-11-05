//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_SQRTCOMMANDCREATOR_H
#define LAB_2_SQRTCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/SqrtCommand.h"

class SqrtCommandCreator : public CommandCreator {
    public:
        Command* create() override {
            return new SqrtCommand();
        }
};

#endif //LAB_2_SQRTCOMMANDCREATOR_H
