//
// Created by Bayramov Nidjat on 31.12.18.
//

#ifndef LAB_3_PLAYER2PLACEMENTCONTROLLER_H
#define LAB_3_PLAYER2PLACEMENTCONTROLLER_H

#include <SFML/Window/Event.hpp>
#include "../Controller.h"

class Player2PlacementController : public Controller {
    public:
        explicit Player2PlacementController(BattleShipModel *battleShipModel) : Controller(battleShipModel) {}
        void handleEvent(sf::Event event) override;
};

#endif //LAB_3_PLAYER2PLACEMENTCONTROLLER_H
