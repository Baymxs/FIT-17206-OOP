//
// Created by Bayramov Nidjat on 08.12.18.
//

#ifndef LAB_3_STARTBUTTON_H
#define LAB_3_STARTBUTTON_H

#include "Button.h"

class StartButton : public Button {
    public:
        StartButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/StartButton/start.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/StartButton/selected_start.png");

            getButtonSprite().setTexture(getButtonNormalTexture());
        }
};

#endif //LAB_3_STARTBUTTON_H
