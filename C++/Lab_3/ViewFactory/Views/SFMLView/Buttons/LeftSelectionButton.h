//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_LEFTSELECTIONBUTTON_H
#define LAB_3_LEFTSELECTIONBUTTON_H

#include "Button.h"

class LeftSelectionButton : public Button {
    public:
        LeftSelectionButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/LeftSelectionButton/left_selection.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/LeftSelectionButton/selected_left_selection.png");

            getButtonSprite().setTexture(getButtonNormalTexture());
        }
};

#endif //LAB_3_LEFTSELECTIONBUTTON_H
