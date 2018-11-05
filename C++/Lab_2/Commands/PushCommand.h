//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_PUSHCOMMAND_H
#define LAB_2_PUSHCOMMAND_H

#include "../Command.h"

class PushCommand : public Command{
    public:
        void execute(std::vector<std::string>) override;
};

#endif //LAB_2_PUSHCOMMAND_H