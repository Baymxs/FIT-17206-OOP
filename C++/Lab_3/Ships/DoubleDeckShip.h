//
// Created by Bayramov Nidjat on 22.12.18.
//

#ifndef LAB_3_DOUBLEDECKSHIP_H
#define LAB_3_DOUBLEDECKSHIP_H

#include "Ship.h"

class DoubleDeckShip : public Ship {
    public:
        DoubleDeckShip() {
            getDecks().emplace_back(0, 0);
            getDecks().emplace_back(1, 0);
        }
};

#endif //LAB_3_DOUBLEDECKSHIP_H
