//
// Created by Bayramov Nidjat on 09.12.18.
//

#ifndef LAB_3_OPTIONSBUTTON_H
#define LAB_3_OPTIONSBUTTON_H

#include "Button.h"

class OptionsButton : public Button {
    public:
        OptionsButton(int x, int y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/OptionsButton/options.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/OptionsButton/selected_options.png");

            getButtonSprite().setTexture(getButtonNormalTexture());
            getButtonSprite().setPosition(x, y);
        }
};

#endif //LAB_3_OPTIONSBUTTON_H
