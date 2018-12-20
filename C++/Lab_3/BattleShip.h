//
// Created by Bayramov Nidjat on 17.11.18.
//

#ifndef LAB_3_BATTLESHIP_H
#define LAB_3_BATTLESHIP_H

#include <string>
#include "BattleShipModel.h"
#include "ViewFactory/View.h"
#include "ViewFactory/Views/SFMLView/ControllerFactory/Controller.h"

class BattleShip {
    private:
        BattleShipModel *battleShipModel;
        Controller *battleShipController;
        View *battleShipView;

    public:
        explicit BattleShip(const std::string &game_mode);
        void startGame();
};

#endif //LAB_3_BATTLESHIP_H
