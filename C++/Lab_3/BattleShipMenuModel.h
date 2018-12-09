//
// Created by Bayramov Nidjat on 05.12.18.
//

#ifndef LAB_3_BATTLESHIPMENUMODEL_H
#define LAB_3_BATTLESHIPMENUMODEL_H

#include <string>

class BattleShipMenuModel {
    private:
        std::string menu_choice;
    public:
        std::string getMenuChoice() {
            return  menu_choice;
        }
};

#endif //LAB_3_BATTLESHIPMENUMODEL_H
