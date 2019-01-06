//
// Created by Bayramov Nidjat on 28.12.18.
//

#ifndef LAB_3_HUMANPLAYERCREATOR_H
#define LAB_3_HUMANPLAYERCREATOR_H

#include "../PlayerCreator.h"
#include "../Player.h"
#include "../Players/HumanPlayer.h"

class HumanPlayerCreator : public PlayerCreator {
    HumanPlayer* create(BattleShipModel *battleShipModel) override {
        return new HumanPlayer(battleShipModel);
    }
};

#endif //LAB_3_HUMANPLAYERCREATOR_H
