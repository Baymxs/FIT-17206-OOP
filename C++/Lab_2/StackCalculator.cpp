//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "StackCalculator.h"

#include <vector>
#include <iostream>
#include <fstream>

#include "Command.h"
#include "CommandFactory.h"

std::string StackCalculator::input_stream_name;

void check_definitions(std::vector<std::string> &arg_vector, const Context &context) {
    for (auto &i : arg_vector) {
        auto it = context.define_map.find(i);
        if (it != context.define_map.end()) i = it->second;
    }
}

StackCalculator::StackCalculator(int argc, char* argv[]) {
    if (argc == 1) input_stream_name = "stdin";
    else if (argc == 2) input_stream_name = argv[1];
    else return;
}

void StackCalculator::calculate() {
    Context context;
    if (input_stream_name == "stdin") _readDataFromStdin(context);
    else _readDataFromFile(context);
}

void StackCalculator::_readDataFromStdin(Context &context) {
    std::vector<std::string> arg_vector;
    std::string command_line, word, command_name;
    bool arg_state = false;

    while (true) {
        getline(std::cin, command_line);
        if (command_line == "END") break;

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

void StackCalculator::_readDataFromFile(Context &context) {
    std::ifstream input_file(input_stream_name);

    std::vector<std::string> arg_vector;
    std::string command_line, word, command_name;
    bool arg_state = false;

    while (getline(input_file, command_line)) {
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
