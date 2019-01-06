//
// Created by Bayramov Nidjat on 31.12.18.
//

#ifndef LAB_3_PLAYER1PLACEMENTCONTROLLERCREATOR_H
#define LAB_3_PLAYER1PLACEMENTCONTROLLERCREATOR_H

#include "../ControllerCreator.h"
#include "../Controller.h"
#include "../Controllers/Player1PlacementController.h"

class Player1PlacementControllerCreator : public ControllerCreator {
    Controller* create(BattleShipModel *battleShipModel) override {
        return new Player1PlacementController(battleShipModel);
    }
};

#endif //LAB_3_PLAYER1PLACEMENTCONTROLLERCREATOR_H
