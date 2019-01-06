//
// Created by Bayramov Nidjat on 28.12.18.
//

#ifndef LAB_3_HUMANPLAYER_H
#define LAB_3_HUMANPLAYER_H


#include "../Player.h"

class HumanPlayer : public Player {
    explicit HumanPlayer(BattleShipModel *battleShipModel) : Player(battleShipModel) {

    }
};


#endif //LAB_3_HUMANPLAYER_H
