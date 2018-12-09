//
// Created by Bayramov Nidjat on 21.11.18.
//

#ifndef LAB_3_MENUWINDOW_H
#define LAB_3_MENUWINDOW_H


#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "../Window.h"
#include "../../Buttons/StartButton.h"
#include "../../Buttons/OptionsButton.h"
#include "../../Buttons/ModeLeftSelectionButton.h"
#include "../../Buttons/ModeRightSelectionButton.h"

class MenuWindow : public Window {
    private:
        StartButton startButton{275, 200};
        ModeLeftSelectionButton leftModeSelectionButton1{90, 349};
        ModeRightSelectionButton rightModeSelectionButton1{335, 349};
        ModeLeftSelectionButton leftModeSelectionButton2{400, 349};
        ModeRightSelectionButton rightModeSelectionButton2{645, 349};
        OptionsButton optionsButton{245, 419};
        void drawBackground();
        void drawButtons();
    public:
        void render(BattleShipModel* battleShipModel) override;
};

#endif //LAB_3_MENUWINDOW_H
