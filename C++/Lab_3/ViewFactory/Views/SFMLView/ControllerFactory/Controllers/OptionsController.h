//
// Created by Bayramov Nidjat on 16.12.18.
//

#ifndef LAB_3_OPTIONSCONTROLLER_H
#define LAB_3_OPTIONSCONTROLLER_H

#include "../Controller.h"
#include <SFML/Window/Event.hpp>

class OptionsController : public Controller {
    public:
        explicit OptionsController(BattleShipModel *battleShipModel) : Controller(battleShipModel) {}
        void handleEvent(sf::Event event) override;
};

#endif //LAB_3_OPTIONSCONTROLLER_H
