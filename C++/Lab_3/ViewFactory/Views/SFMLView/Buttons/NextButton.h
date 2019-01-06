//
// Created by Bayramov Nidjat on 30.12.18.
//

#ifndef LAB_3_NEXTBUTTON_H
#define LAB_3_NEXTBUTTON_H

#include "Button.h"

class NextButton : public Button {
    public:
        NextButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonInvisibleTexture().loadFromFile("../src/Buttons/NextButton/invisible_next.png");
            getButtonNormalTexture().loadFromFile("../src/Buttons/NextButton/next.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/NextButton/selected_next.png");
        }
};

#endif //LAB_3_NEXTBUTTON_H
