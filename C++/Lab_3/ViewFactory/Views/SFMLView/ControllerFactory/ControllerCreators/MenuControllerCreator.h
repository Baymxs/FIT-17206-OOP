//
// Created by Bayramov Nidjat on 30.11.18.
//

#ifndef LAB_3_MENUCONTROLLERCREATOR_H
#define LAB_3_MENUCONTROLLERCREATOR_H

#include "../ControllerCreator.h"
#include "../Controller.h"
#include "../Controllers/MenuController.h"

class MenuControllerCreator : public ControllerCreator {
    Controller* create() override {
        return new MenuController();
    }
};

#endif //LAB_3_MENUCONTROLLERCREATOR_H
