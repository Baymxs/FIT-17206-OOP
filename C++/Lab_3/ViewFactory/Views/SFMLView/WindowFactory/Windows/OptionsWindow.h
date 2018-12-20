//
// Created by Bayramov Nidjat on 16.12.18.
//

#ifndef LAB_3_OPTIONSWINDOW_H
#define LAB_3_OPTIONSWINDOW_H

#include "../Window.h"
#include "../../Buttons/LeftSelectionButton.h"
#include "../../Buttons/RightSelectionButton.h"
#include "../../VolumeSprite.h"
#include "../../Buttons/BackButton.h"
#include "../../Sprites/BackgroundSprite.h"
#include "../../Sprites/MusicModeSprite.h"

class OptionsWindow : public Window{
    private:
        std::vector<Sprite*> sprites {new BackgroundSprite(0, 0),
                                      new MusicModeSprite(290, 130)};

        std::vector<Button*> buttons {new LeftSelectionButton("left_selection_button", 242, 203), new RightSelectionButton("right_selection_button", 460, 203),
                                      new BackButton("back", 10, 540)};

        VolumeSprite volumeSprite;

        void drawSprites();
        void drawButtons();
        void drawVolume();
    public:
        explicit OptionsWindow(BattleShipModel *battleShipModel) : Window(battleShipModel) {}
        void render() override;
};


#endif //LAB_3_OPTIONSWINDOW_H
