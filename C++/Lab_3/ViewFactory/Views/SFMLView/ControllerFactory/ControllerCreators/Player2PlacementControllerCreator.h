//
// Created by Bayramov Nidjat on 31.12.18.
//

#ifndef LAB_3_PLAYER2PLACEMENTCONTROLLERCREATOR_H
#define LAB_3_PLAYER2PLACEMENTCONTROLLERCREATOR_H

#include "../ControllerCreator.h"
#include "../Controller.h"
#include "../Controllers/Player2PlacementController.h"

class Player2PlacementControllerCreator : public ControllerCreator {
    Controller* create(BattleShipModel *battleShipModel) override {
        return new Player2PlacementController(battleShipModel);
    }
};

#endif //LAB_3_PLAYER2PLACEMENTCONTROLLERCREATOR_H
