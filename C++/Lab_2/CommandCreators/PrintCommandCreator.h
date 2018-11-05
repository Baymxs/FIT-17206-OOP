//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_PRINTCOMMANDCREATOR_H
#define LAB_2_PRINTCOMMANDCREATOR_H

#include "../CommandCreator.h"
#include "../Commands/PrintCommand.h"

class PrintCommandCreator : public CommandCreator{
    Command* create() override {
        return new PrintCommand();
    }
};

#endif //LAB_2_PRINTCOMMANDCREATOR_H