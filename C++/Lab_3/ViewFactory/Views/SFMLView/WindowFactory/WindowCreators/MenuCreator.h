//
// Created by Bayramov Nidjat on 21.11.18.
//

#ifndef LAB_3_MENUCREATOR_H
#define LAB_3_MENUCREATOR_H

#include "../WindowCreator.h"
#include "../Window.h"
#include "../Windows/MenuWindow.h"

class MenuCreator : public WindowCreator {
    Window* create(BattleShipModel *battleShipModel) override {
        return new MenuWindow(battleShipModel);
    }
};

#endif //LAB_3_MENUCREATOR_H
