//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_RIGHTSELECTIONBUTTON_H
#define LAB_3_RIGHTSELECTIONBUTTON_H

#include "Button.h"

class RightSelectionButton : public Button {
public:
    RightSelectionButton(int x, int y) {
        getButtonNormalTexture().loadFromFile("../src/Buttons/RightSelectionButton/right_selection.png");
        getButtonSelectedTexture().loadFromFile("../src/Buttons/RightSelectionButton/selected_right_selection.png");
        getButtonSprite().setTexture(getButtonNormalTexture());
        getButtonSprite().setPosition(x, y);
    }
};

#endif //LAB_3_RIGHTSELECTIONBUTTON_H
