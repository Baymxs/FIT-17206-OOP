//
// Created by Bayramov Nidjat on 16.11.18.
//

#ifndef LAB_3_BATTLESHIPMODEL_H
#define LAB_3_BATTLESHIPMODEL_H

#include <string>
#include <vector>
#include "BattleShipMenuModel.h"

class BattleShipModel {
    private:
        std::string game_mode;
        std::string game_stage;
        bool controller_changes;
        bool window_changes;
        BattleShipMenuModel battleShipMenuModel;
    public:
        explicit BattleShipModel(const std::string &game_mode) {
            this->game_mode = game_mode;
            setGameStage("Menu");
        }

        std::string &getGameMode() {
            return game_mode;
        }

        std::string &getGameStage() {
            return game_stage;
        }

        const bool &getControllerChanges() const{
            return controller_changes;
        }

        const bool &getWindowChanges() const{
            return window_changes;
        }

        BattleShipMenuModel &getBattleShipMenuModel(){
            return battleShipMenuModel;
        }

        void setGameStage(const std::string &game_stage) {
            this->game_stage = game_stage;
            controller_changes = window_changes = true;
        }

        void setControllerChanges(const bool &controller_changes) {
            this->controller_changes = controller_changes;
        }

        void setWindowChanges(const bool &window_changes) {
            this->window_changes = window_changes;
        }
};

#endif //LAB_3_BATTLESHIPMODEL_H
