//
// Created by Bayramov Nidjat on 31.12.18.
//

#ifndef LAB_3_BATTLEBUTTON_H
#define LAB_3_BATTLEBUTTON_H

#include "Button.h"

class BattleButton : public Button {
    public:
        BattleButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonInvisibleTexture().loadFromFile("../src/Buttons/BattleButton/invisible_battle.png");
            getButtonNormalTexture().loadFromFile("../src/Buttons/BattleButton/battle.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/BattleButton/selected_battle.png");
        }
};

#endif //LAB_3_BATTLEBUTTON_H
