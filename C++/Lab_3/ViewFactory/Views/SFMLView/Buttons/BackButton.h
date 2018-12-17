//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_BACKBUTTON_H
#define LAB_3_BACKBUTTON_H

#include "Button.h"

class BackButton : public Button {
public:
    BackButton(int x, int y) {
        getButtonNormalTexture().loadFromFile("../src/Buttons/BackButton/back.png");
        getButtonSelectedTexture().loadFromFile("../src/Buttons/BackButton/selected_back.png");

        getButtonSprite().setTexture(getButtonNormalTexture());
        getButtonSprite().setPosition(x, y);
    }
};

#endif //LAB_3_BACKBUTTON_H
