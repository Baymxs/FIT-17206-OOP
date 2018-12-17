//
// Created by Bayramov Nidjat on 21.11.18.
//

#ifndef LAB_3_WINDOWFACTORY_H
#define LAB_3_WINDOWFACTORY_H

#include <map>
#include <string>
#include <exception>

#include "WindowCreator.h"
#include "Window.h"

class WindowFactory {
    private:
        //We placed the constructor in a private area so that it was impossible to create objects of type WindowFactory
        //We can't use "new" keyword
        WindowFactory() = default;

        //Create a container "map" that stores commands.
        std::map<std::string, WindowCreator*> windows;

    public:
        virtual ~WindowFactory() {
            for (auto item : windows) {
                delete item.second;
            }
        };

        static WindowFactory& getInstance() {
            //Variable viewFactory of type WindowFactory will be in the static memory area only after calling the method
            static WindowFactory windowFactory;
            return windowFactory;
        }

        Window* getWindow(BattleShipModel *battleShipModel) {
            auto it = windows.find(battleShipModel->getGameStage());
            if (it == windows.end()) {}
            return  it->second->create(battleShipModel);
        }

        void registerWindows(const std::string &window_name, WindowCreator *creator) {
            //We find the item from map-container "windows" with "window_name" key
            auto it = windows.find(window_name);
            //If the map-container already has an item with key "window_name"
            if (it != windows.end()) {
                //If the value of item we found is the creator that we gave to the function as an argument return
                if (it->second == creator) return;
                else delete it->second;
            }
            windows[window_name] = creator;
        }
};

#endif //LAB_3_WINDOWFACTORY_H
