//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_POPCOMMAND_H
#define LAB_2_POPCOMMAND_H

#include "../Command.h"

class PopCommand : public Command {
public:
    void execute(std::vector<std::string> arg_vector, Context &context) override;
};

#endif //LAB_2_POPCOMMAND_H