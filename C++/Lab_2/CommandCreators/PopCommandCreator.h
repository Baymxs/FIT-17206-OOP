//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_POPCOMMANDCREATOR_H
#define LAB_2_POPCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/PopCommand.h"

class PopCommandCreator : public CommandCreator{
    Command* create() override {
        return new PopCommand();
    }
};

#endif //LAB_2_POPCOMMANDCREATOR_H