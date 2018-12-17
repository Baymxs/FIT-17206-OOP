//
// Created by Bayramov Nidjat on 08.12.18.
//

#ifndef LAB_3_STARTBUTTON_H
#define LAB_3_STARTBUTTON_H

#include "Button.h"

class StartButton : public Button {
    public:
        StartButton(int x, int y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/StartButton/start.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/StartButton/selected_start.png");

            getButtonSprite().setTexture(getButtonNormalTexture());
            getButtonSprite().setPosition(x, y);
        }
};

#endif //LAB_3_STARTBUTTON_H
