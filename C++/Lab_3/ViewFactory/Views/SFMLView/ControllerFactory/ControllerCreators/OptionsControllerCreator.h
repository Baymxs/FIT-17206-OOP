//
// Created by Bayramov Nidjat on 16.12.18.
//

#ifndef LAB_3_OPTIONSCONTROLLERCREATOR_H
#define LAB_3_OPTIONSCONTROLLERCREATOR_H

#include "../ControllerCreator.h"
#include "../Controller.h"
#include "../Controllers/OptionsController.h"

class OptionsControllerCreator : public ControllerCreator {
    Controller* create(BattleShipModel *battleShipModel) override {
        return new OptionsController(battleShipModel);
    }
};

#endif //LAB_3_OPTIONSCONTROLLERCREATOR_H
