//
// Created by Bayramov Nidjat on 09.12.18.
//

#ifndef LAB_3_MODERIGHTSELECTIONBUTTON_H
#define LAB_3_MODERIGHTSELECTIONBUTTON_H

#include "Button.h"

class ModeRightSelectionButton : public Button {
    public:
        ModeRightSelectionButton(int x, int y) {
            getButtonTexture().loadFromFile("../src/Buttons/RightSelectionButton/mode_right_selection.png");
            getButtonSprite().setTexture(getButtonTexture());
            getButtonSprite().setPosition(x, y);
        }
};

#endif //LAB_3_MODERIGHTSELECTIONBUTTON_H
