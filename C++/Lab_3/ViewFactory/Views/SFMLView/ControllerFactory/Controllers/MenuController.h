//
// Created by Bayramov Nidjat on 30.11.18.
//

#ifndef LAB_3_MENUCONTROLLER_H
#define LAB_3_MENUCONTROLLER_H

#include <SFML/Window/Event.hpp>
#include "../Controller.h"

class MenuController : public Controller {
    public:
        void handleEvent(sf::Event event) override;
};

#endif //LAB_3_MENUCONTROLLER_H
