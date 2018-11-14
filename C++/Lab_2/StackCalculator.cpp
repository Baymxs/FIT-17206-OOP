//
// Created by Bayramov Nidjat on 04.11.18.
//

#include "StackCalculator.h"

#include <vector>

#include "Command.h"
#include "CommandFactory.h"
#include "Parser.h"

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
    std::string command_line;

    Context context(output_stream);

    Parser parser;
    while (getline(input_stream, command_line)) {
        parser.parseLine(command_line);

        try {
            //We added auto_ptr, so that when you exit the block try catch or when an exceptions occurs, we were sure 
            //that the distractor of Command object would be called
            std::auto_ptr<Command> command(CommandFactory::getInstance().getCommand(parser.getCommandName()));
            std::vector<std::string> arguments = parser.getArguments();
            check_definitions(arguments, context);
            command->execute(arguments, context);
        } catch (std::exception &ex) {
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
}

