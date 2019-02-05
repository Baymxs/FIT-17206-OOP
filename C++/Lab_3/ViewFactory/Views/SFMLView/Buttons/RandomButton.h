//
// Created by Bayramov Nidjat on 06.01.19.
//

#ifndef LAB_3_RANDOMBUTTON_H
#define LAB_3_RANDOMBUTTON_H

#include "Button.h"

class RandomButton : public Button {
    public:
        RandomButton(const std::string &button_name, const int &x, const int &y) : Button(button_name, x, y) {
            getButtonNormalTexture().loadFromFile("../src/Buttons/RandomButton/random.png");
            getButtonSelectedTexture().loadFromFile("../src/Buttons/RandomButton/selected_random.png");
        }
};

#endif //LAB_3_RANDOMBUTTON_H
