//
// Created by Bayramov Nidjat on 23.12.18.
//

#ifndef LAB_3_FOURDECKSHIP_H
#define LAB_3_FOURDECKSHIP_H

#include "Ship.h"

class FourDeckShip : public Ship {
    public:
        FourDeckShip() {
            getDecks().emplace_back(0, 0);
            getDecks().emplace_back(1, 0);
            getDecks().emplace_back(2, 0);
            getDecks().emplace_back(3, 0);

                setNearCells();
        }
};

#endif //LAB_3_FOURDECKSHIP_H
