//
// Created by Bayramov Nidjat on 31.12.18.
//

#ifndef LAB_3_PLAYER1PLACEMENTCREATOR_H
#define LAB_3_PLAYER1PLACEMENTCREATOR_H

#include "../WindowCreator.h"
#include "../Window.h"
#include "../Windows/Player1PlacementWindow.h"

class Player1PlacementCreator : public WindowCreator {
    Window* create(BattleShipModel *battleShipModel) override {
        return new Player1PlacementWindow(battleShipModel);
    }
};

#endif //LAB_3_PLAYER1PLACEMENTCREATOR_H
