//
// Created by Bayramov Nidjat on 21.12.18.
//

#ifndef LAB_3_SHIPPLACEMENTCREATOR_H
#define LAB_3_SHIPPLACEMENTCREATOR_H

#include "../WindowCreator.h"
#include "../Window.h"
#include "../Windows/ShipPlacementWindow.h"

class ShipPlacementCreator : public WindowCreator {
    Window* create(BattleShipModel *battleShipModel) override {
        return new ShipPlacementWindow(battleShipModel);
    }
};

#endif //LAB_3_SHIPPLACEMENTCREATOR_H
