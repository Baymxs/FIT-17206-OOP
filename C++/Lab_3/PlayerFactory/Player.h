//
// Created by Bayramov Nidjat on 28.12.18.
//

#ifndef LAB_3_PLAYER_H
#define LAB_3_PLAYER_H

#include "../BattleShipModel.h"

class Player {
    private:
        BattleShipModel *battleShipModel;
    public:
        explicit Player(BattleShipModel *battleShipModel) {
            this->battleShipModel = battleShipModel;
        }

        BattleShipModel *getBattleShipModel() {
            return battleShipModel;
        }
};

#endif //LAB_3_PLAYER_H
