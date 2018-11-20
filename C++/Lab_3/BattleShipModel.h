//
// Created by Bayramov Nidjat on 16.11.18.
//

#ifndef LAB_3_BATTLESHIPMODEL_H
#define LAB_3_BATTLESHIPMODEL_H

#include <string>

class BattleShipModel {
    private:
        std::string game_stage;
    public:
        BattleShipModel() {
            game_stage = "menu";
        }

        std::string getGameStage() const;
};


#endif //LAB_3_BATTLESHIPMODEL_H
