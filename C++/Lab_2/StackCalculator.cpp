//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "StackCalculator.h"

#include <vector>

#include "Command.h"
#include "CommandFactory.h"

void check_definitions(std::vector<std::string> &arg_vector, Context &context) {
    for (auto &i : arg_vector) {
        auto it = context.findMapValueByKey(i);
        if (it != context.getEndIterator()) i = it->second;
    }
}

StackCalculator::StackCalculator(std::istream &istream, std::ostream &ostream)
    : input_stream(istream), output_stream(ostream){
}

void StackCalculator::calculate() {
    Context context(output_stream);
    _readData(context);
}

void StackCalculator::_readData(Context &context) {
    std::vector<std::string> arg_vector;
    std::string command_line, word, command_name;
    bool arg_state = false;

    while (getline(input_stream, command_line)) {
        for (int i = 0; i < command_line.length(); i++) {
            if (command_line[i] == ' ') {
                if (!arg_state) {
                    command_name = word;
                    word.clear();
                    arg_state = true;
                } else {
                    arg_vector.push_back(word);
                    word.clear();
                }
            } else if(i == command_line.length() - 1) {
                word += command_line[i];
                if (command_name.empty()) command_name = word;
                else arg_vector.push_back(word);
            }
            else word += command_line[i];
        }
        try {
            Command *command = CommandFactory::getInstance().getCommand(command_name);
            check_definitions(arg_vector, context);
            command->execute(arg_vector, context);
        } catch (std::exception &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        arg_state = false;
        command_name.clear();
        arg_vector.clear();
        word.clear();
    }
}
