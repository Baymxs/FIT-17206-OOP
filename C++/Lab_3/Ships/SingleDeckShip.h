//
// Created by Bayramov Nidjat on 22.12.18.
//

#ifndef LAB_3_SINGLEDECKSHIP_H
#define LAB_3_SINGLEDECKSHIP_H

#include "Ship.h"

class SingleDeckShip : public Ship {
    public:
        SingleDeckShip() {
            getDecks().emplace_back(0, 0);
        }
};

#endif //LAB_3_SINGLEDECKSHIP_H
