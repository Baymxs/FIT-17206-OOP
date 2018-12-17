//
// Created by Bayramov Nidjat on 29.11.18.
//

#ifndef LAB_3_CONTROLLERFACTORY_H
#define LAB_3_CONTROLLERFACTORY_H

#include <map>
#include <string>
#include "ControllerCreator.h"
#include "Controller.h"

class ControllerFactory {
    private:
        //We placed the constructor in a private area so that it was impossible to create objects of type ControllerFactory
        //We can't use "new" keyword
        ControllerFactory() = default;

        //Create a container "map" that stores controllers
        std::map<std::string, ControllerCreator*> controllers;

    public:
        virtual ~ControllerFactory() {
            for (auto item : controllers) {
                delete item.second;
            }
        };

        static ControllerFactory& getInstance() {
            //Variable controllerFactory of type ControllerFactory will be in the static memory area only after calling the method
            static ControllerFactory controllerFactory;
            return controllerFactory;
        }

        Controller* getController(BattleShipModel *battleShipModel) {
            auto it = controllers.find(battleShipModel->getGameStage());
            if (it == controllers.end()) {}
            return  it->second->create(battleShipModel);
        }

        void registerController(const std::string &controller_name, ControllerCreator *creator) {
            //We find the item from map-container "controllers" with "controller_name" key
            auto it = controllers.find(controller_name);
            //If the map-container already has an item with key "controller_name"
            if (it != controllers.end()) {
                //If the value of item we found is the creator that we gave to the function as an argument return
                if (it->second == creator) return;
                else delete it->second;
            }
            controllers[controller_name] = creator;
        }
};

#endif //LAB_3_CONTROLLERFACTORY_H
