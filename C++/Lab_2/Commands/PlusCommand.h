//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_PLUSCOMMAND_H
#define LAB_2_PLUSCOMMAND_H

#include "../Command.h"

class PlusCommand : public Command {
    public:
        void execute(std::vector<std::string>, Context &context) override;
};

#endif //LAB_2_PLUSCOMMAND_H