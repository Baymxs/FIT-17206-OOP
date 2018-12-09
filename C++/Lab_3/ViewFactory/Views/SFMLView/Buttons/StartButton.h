//
// Created by Bayramov Nidjat on 08.12.18.
//

#ifndef LAB_3_STARTBUTTON_H
#define LAB_3_STARTBUTTON_H

#include "Button.h"

class StartButton : public Button {
    public:
        StartButton(int x, int y) {
            getButtonTexture().loadFromFile("../src/Buttons/StartButton/Start.png");
            getButtonSprite().setTexture(getButtonTexture());
            getButtonSprite().setPosition(x, y);
        }
};

#endif //LAB_3_STARTBUTTON_H
