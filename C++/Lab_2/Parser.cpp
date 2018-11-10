//
// Created by Bayramov Nidjat on 10.11.18.
//

#include "Parser.h"
#include <iostream>

void Parser::parseLine(std::string command_line) {
    std::vector<std::string> arguments;
    std::string word, command_name;
    bool arg_state = false;

    for (int i = 0; i < command_line.length(); i++) {
        if (command_line[i] == ' ') {
            if (!arg_state) {
                command_name = word;
                word.clear();
                arg_state = true;
            } else {
                arguments.push_back(word);
                word.clear();
            }
        } else if (i == command_line.length() - 1) {
            word += command_line[i];
            if (command_name.empty()) command_name = word;
            else arguments.push_back(word);
        } else word += command_line[i];
    }

    _command_name = command_name;
    _arguments = arguments;
}

std::string Parser::getCommandName() {
    return _command_name;
}

std::vector<std::string> Parser::getArguments() {
    return _arguments;
}

