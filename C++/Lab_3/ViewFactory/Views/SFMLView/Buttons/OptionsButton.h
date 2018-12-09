//
// Created by Bayramov Nidjat on 09.12.18.
//

#ifndef LAB_3_OPTIONSBUTTON_H
#define LAB_3_OPTIONSBUTTON_H

#include "Button.h"

class OptionsButton : public Button {
    public:
        OptionsButton(int x, int y) {
            getButtonTexture().loadFromFile("../src/Buttons/OptionsButton/Options.png");
            getButtonSprite().setTexture(getButtonTexture());
            getButtonSprite().setPosition(x, y);
        }
};

#endif //LAB_3_OPTIONSBUTTON_H
