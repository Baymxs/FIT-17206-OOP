//
// Created by Bayramov Nidjat on 23.12.18.
//

#ifndef LAB_3_THREEDECKSHIP_H
#define LAB_3_THREEDECKSHIP_H

#include "Ship.h"

class ThreeDeckShip : public Ship {
    public:
        ThreeDeckShip() {
            getDecks().emplace_back(0, 0);
            getDecks().emplace_back(1, 0);
            getDecks().emplace_back(2, 0);
        }
};

#endif //LAB_3_THREEDECKSHIP_H
