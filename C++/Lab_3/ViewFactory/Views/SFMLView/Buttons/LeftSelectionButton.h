//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_LEFTSELECTIONBUTTON_H
#define LAB_3_LEFTSELECTIONBUTTON_H

#include "Button.h"

class LeftSelectionButton : public Button {
public:
    LeftSelectionButton(int x, int y) {
        getButtonNormalTexture().loadFromFile("../src/Buttons/LeftSelectionButton/left_selection.png");
        getButtonSelectedTexture().loadFromFile("../src/Buttons/LeftSelectionButton/selected_left_selection.png");

        getButtonSprite().setTexture(getButtonNormalTexture());
        getButtonSprite().setPosition(x, y);
    }
};

#endif //LAB_3_LEFTSELECTIONBUTTON_H
