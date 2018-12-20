//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_RIGHTSELECTIONBUTTON_H
#define LAB_3_RIGHTSELECTIONBUTTON_H

#include "Button.h"

class RightSelectionButton : public Button {
    public:
        RightSelectionButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/RightSelectionButton/right_selection.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/RightSelectionButton/selected_right_selection.png");

            getButtonSprite().setTexture(getButtonNormalTexture());
        }
};

#endif //LAB_3_RIGHTSELECTIONBUTTON_H
