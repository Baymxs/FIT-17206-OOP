//
// Created by Bayramov Nidjat on 16.12.18.
//

#ifndef LAB_3_EXITBUTTON_H
#define LAB_3_EXITBUTTON_H

#include "Button.h"

class ExitButton : public Button {
    public:
        ExitButton(int x, int y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/ExitButton/exit.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/ExitButton/selected_exit.png");

            getButtonSprite().setTexture(getButtonNormalTexture());
            getButtonSprite().setPosition(x, y);
        }
};

#endif //LAB_3_EXITBUTTON_H
