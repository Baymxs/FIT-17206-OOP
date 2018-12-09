//
// Created by Bayramov Nidjat on 17.11.18.
//

#ifndef LAB_3_VIEWFACTORY_H
#define LAB_3_VIEWFACTORY_H

#include <map>
#include <string>
#include <exception>

#include "ViewCreator.h"
#include "View.h"

class ViewFactory {
    private:
        //We placed the constructor in a private area so that it was impossible to create objects of type ViewFactory
        //We can't use "new" keyword
        ViewFactory() = default;

        //Create a container "map" that stores views.
        std::map<std::string, ViewCreator*> views;

    public:
        virtual ~ViewFactory() {
            for (auto item : views) {
                delete item.second;
            }
        };

        static ViewFactory& getInstance() {
            //Variable viewFactory of type ViewFactory will be in the static memory area only after calling the method
            static ViewFactory viewFactory;
            return viewFactory;
        }

        View* getView(const std::string &view_name) {
            auto it = views.find(view_name);
            if (it == views.end()) {}
            return  it->second->create();
        }

        void registerView(const std::string &view_name, ViewCreator *creator) {
            //We find the item from map-container "views" with "view_name" key
            auto it = views.find(view_name);
            //If the map-container already has an item with key "view_name"
            if (it != views.end()) {
                //If the value of item we found is the creator that we gave to the function as an argument return
                if (it->second == creator) return;
                else delete it->second;
            }
            views[view_name] = creator;
        }
};

#endif //LAB_3_VIEWFACTORY_H