//
// Created by Bayramov Nidjat on 16.11.18.
//

#ifndef LAB_3_BATTLESHIPMODEL_H
#define LAB_3_BATTLESHIPMODEL_H

#include <string>
#include <vector>
#include "BattleShipMenuModel.h"

class BattleShipModel {
    private:
        std::string game_stage = "Menu";
        BattleShipMenuModel battleShipMenuModel;
    public:
        std::string getGameStage() {
            return game_stage;
        }
};

#endif //LAB_3_BATTLESHIPMODEL_H
