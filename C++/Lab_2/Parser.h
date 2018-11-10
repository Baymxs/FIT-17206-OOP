//
// Created by Bayramov Nidjat on 10.11.18.
//

#ifndef LAB_2_PARSER_H
#define LAB_2_PARSER_H


#include <string>
#include <vector>
#include <map>

class Parser {
    private:
        std::string _command_name;
        std::vector<std::string> _arguments;
    public:
        void parseLine(std::string command_line);
        std::string getCommandName();
        std::vector<std::string> getArguments();
};


#endif //LAB_2_PARSER_H
