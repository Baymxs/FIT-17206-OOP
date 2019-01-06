//
// Created by Bayramov Nidjat on 18.12.18.
//

#ifndef LAB_3_BACKBUTTON_H
#define LAB_3_BACKBUTTON_H

#include "Button.h"

class BackButton : public Button {
    public:
        BackButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/BackButton/back.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/BackButton/selected_back.png");
        }
};

#endif //LAB_3_BACKBUTTON_H
