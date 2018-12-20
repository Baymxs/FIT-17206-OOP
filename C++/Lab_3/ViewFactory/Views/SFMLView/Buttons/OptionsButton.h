//
// Created by Bayramov Nidjat on 09.12.18.
//

#ifndef LAB_3_OPTIONSBUTTON_H
#define LAB_3_OPTIONSBUTTON_H

#include "Button.h"

class OptionsButton : public Button {
    public:
        OptionsButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/OptionsButton/options.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/OptionsButton/selected_options.png");

            getButtonSprite().setTexture(getButtonNormalTexture());
        }
};

#endif //LAB_3_OPTIONSBUTTON_H
