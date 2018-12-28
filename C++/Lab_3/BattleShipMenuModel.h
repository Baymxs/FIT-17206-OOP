//
// Created by Bayramov Nidjat on 05.12.18.
//

#ifndef LAB_3_BATTLESHIPMENUMODEL_H
#define LAB_3_BATTLESHIPMENUMODEL_H

#include <string>

class BattleShipMenuModel {
    private:
        std::string menu_move;

        int player1 = 1, player2 = 1;
        int volume_selection = 1;
        int music_mode_changed = false;
    public:
        const std::string &getMenuMove() const {
            return menu_move;
        }

        const int &getPlayer1() const {
            return player1;
        }

        const int &getPlayer2() const {
            return player2;
        }

        const int &getVolumeSelection() const {
            return volume_selection;
        }

        const int &getMusicModeChanged() const {
            return music_mode_changed;
        }

        void setMenuMove(const std::string &menu_move) {
            this->menu_move = menu_move;
        }

        void setPlayer1(const int &selected_player) {
            player1 = selected_player;
        }

        void setPlayer2(const int &selected_player) {
            player2 = selected_player;
        }

        void setVolumeSelection(const int &volume_selection) {
            this->volume_selection = volume_selection;
            music_mode_changed = true;
        }

        void setMusicModeChanged(const bool &music_mode_changed) {
            this->music_mode_changed = music_mode_changed;
        }
};

#endif //LAB_3_BATTLESHIPMENUMODEL_H
