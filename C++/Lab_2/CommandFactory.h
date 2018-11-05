//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_COMMANDFACTORY_H
#define LAB_2_COMMANDFACTORY_H

#include <map>

#include "CommandCreator.h"

class CommandFactory {

    private:
        //We placed the constructor in a private area so that it was impossible to create objects of type CommandFactory
        //We can't use "new" keyword
        CommandFactory() = default;

        //Create a container "map" that stores commands.
        std::map<std::string, CommandCreator*> commands;

    public:
        virtual ~CommandFactory() {
            for (auto item : commands) {
                delete item.second;
            }
        };

        static CommandFactory& getInstance() {
            //Variable commandFactory of type CommandFactory will be in the static memory area only after calling the method
            static CommandFactory commandFactory;
            return commandFactory;
        }

        Command* getCommand(const std::string &name) {
            auto it = commands.find(name);
            if (it == commands.end()) {
                throw std::exception();
            }
            return  it->second->create();
        }

        void registerCommand(const std::string &name, CommandCreator *creator) {
            //We find the item from map-container "container" with "name" key
            auto it = commands.find(name);
            //If the map-container already has an item with key "name"
            if (it != commands.end()) {
                //If the value of item we found is the creator that we gave to the function as an argument return
                if (it->second == creator) return;
                else delete it->second;
            }
            commands[name] = creator;
        }
};

#endif //LAB_2_COMMANDFACTORY_H
