//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_SHIPPLACEMENTCONTROLLERCREATOR_H
#define LAB_3_SHIPPLACEMENTCONTROLLERCREATOR_H

#include "../ControllerCreator.h"
#include "../Controller.h"
#include "../Controllers/ShipPlacementController.h"

class ShipPlacementControllerCreator : public ControllerCreator {
    Controller* create(BattleShipModel *battleShipModel) override {
        return new ShipPlacementController(battleShipModel);
    }
};

#endif //LAB_3_SHIPPLACEMENTCONTROLLERCREATOR_H
