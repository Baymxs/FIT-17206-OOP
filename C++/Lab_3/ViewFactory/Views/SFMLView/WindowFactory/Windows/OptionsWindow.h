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

class OptionsWindow : public Window{
    private:
        sf::Sprite background_sprite;
        sf::Sprite music_sprite;

        BackButton backButton{10, 540};
        LeftSelectionButton leftSelectionButton{242, 203};
        RightSelectionButton rightSelectionButton{460, 203};

        VolumeSprite volumeSprite;

        void drawBackground();
        void drawButtons();
        void drawVolume();
    public:
        explicit OptionsWindow(BattleShipModel *battleShipModel) : Window(battleShipModel) {
            static sf::Texture background_texture;
            background_texture.loadFromFile("../src/Background/menu_background.jpg");
            background_sprite.setTexture(background_texture);

            static sf::Texture music_texture;
            music_texture.loadFromFile("../src/Background/music.png");
            music_sprite.setTexture(music_texture);
            music_sprite.setPosition(290, 130);

        }
        void render() override;

};


#endif //LAB_3_OPTIONSWINDOW_H
