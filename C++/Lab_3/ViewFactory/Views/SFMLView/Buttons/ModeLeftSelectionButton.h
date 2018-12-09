//
// Created by Bayramov Nidjat on 09.12.18.
//

#ifndef LAB_3_MODELEFTSELECTIONBUTTON_H
#define LAB_3_MODELEFTSELECTIONBUTTON_H

#include "Button.h"

class ModeLeftSelectionButton : public Button {
    public:
        ModeLeftSelectionButton(int x, int y) {
            getButtonTexture().loadFromFile("../src/Buttons/LeftSelectionButton/mode_left_selection.png");
            getButtonSprite().setTexture(getButtonTexture());
            getButtonSprite().setPosition(x, y);
        }
};

#endif //LAB_3_MODELEFTSELECTIONBUTTON_H
