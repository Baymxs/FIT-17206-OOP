//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_PRINTCOMMAND_H
#define LAB_2_PRINTCOMMAND_H

#include "../Command.h"

class PrintCommand : public Command {
    public:
        void execute(std::vector<std::string>) override;
};

#endif //LAB_2_PRINTCOMMAND_H