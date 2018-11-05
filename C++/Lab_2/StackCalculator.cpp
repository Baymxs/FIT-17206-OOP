//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "StackCalculator.h"

#include <vector>
#include <iostream>
#include <fstream>

#include "Command.h"
#include "CommandFactory.h"

std::stack<double> StackCalculator::stack;
std::map<std::string, std::string> StackCalculator::define_map;
std::string StackCalculator::input_stream_name;

void check_definitions(std::vector<std::string> &arg_vector) {
    for (int i = 0; i < arg_vector.size(); i++) {
        auto it = StackCalculator::define_map.find(arg_vector[i]);
        if (it != StackCalculator::define_map.end()) arg_vector[i] = it->second;
    }
}

StackCalculator::StackCalculator(int argc, char* argv[]) {
    if (argc == 1) input_stream_name = "stdin";
    else if (argc == 2) input_stream_name = argv[1];
    else return;
}

void StackCalculator::calculate() {
    if (input_stream_name == "stdin") _readDataFromStdin();
    else _readDataFromFile();
}

void StackCalculator::_readDataFromStdin() {
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
            check_definitions(arg_vector);
            command->execute(arg_vector);
        } catch (std::exception &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        arg_state = false;
        command_name.clear();
        arg_vector.clear();
        word.clear();
    }
}

void StackCalculator::_readDataFromFile() {
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
            check_definitions(arg_vector);
            command->execute(arg_vector);
        } catch (std::exception &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
        arg_state = false;
        command_name.clear();
        arg_vector.clear();
        word.clear();
    }
}
