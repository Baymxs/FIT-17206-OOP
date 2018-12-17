//
// Created by Bayramov Nidjat on 16.12.18.
//

#ifndef LAB_3_OPTIONSCREATOR_H
#define LAB_3_OPTIONSCREATOR_H

#include "../WindowCreator.h"
#include "../Window.h"
#include "../Windows/OptionsWindow.h"

class OptionsCreator : public WindowCreator {
    Window* create(BattleShipModel *battleShipModel) override {
        return new OptionsWindow(battleShipModel);
    }
};

#endif //LAB_3_OPTIONSCREATOR_H
