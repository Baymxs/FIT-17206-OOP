//
// Created by Bayramov Nidjat on 31.12.18.
//

#ifndef LAB_3_PLAYER2PLACEMENTCREATOR_H
#define LAB_3_PLAYER2PLACEMENTCREATOR_H

#include "../WindowCreator.h"
#include "../Window.h"
#include "../Windows/Player2PlacementWindow.h"

class Player2PlacementCreator : public WindowCreator {
    Window* create(BattleShipModel *battleShipModel) override {
        return new Player2PlacementWindow(battleShipModel);
    }
};

#endif //LAB_3_PLAYER2PLACEMENTCREATOR_H
