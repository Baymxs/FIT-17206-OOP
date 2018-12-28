//
// Created by Bayramov Nidjat on 20.12.18.
//

#ifndef LAB_3_SHIPPLACEMENTCONTROLLER_H
#define LAB_3_SHIPPLACEMENTCONTROLLER_H

#include <SFML/Window/Event.hpp>
#include "../Controller.h"

class ShipPlacementController : public Controller {
    public:
        explicit ShipPlacementController(BattleShipModel *battleShipModel) : Controller(battleShipModel) {}
        void handleEvent(sf::Event event) override;
};

#endif //LAB_3_SHIPPLACEMENTCONTROLLER_H
