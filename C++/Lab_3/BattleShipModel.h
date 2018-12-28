//
// Created by Bayramov Nidjat on 16.11.18.
//

#ifndef LAB_3_BATTLESHIPMODEL_H
#define LAB_3_BATTLESHIPMODEL_H

#include <string>
#include <vector>
#include "BattleShipMenuModel.h"
#include "Ships/SingleDeckShip.h"
#include "Ships/DoubleDeckShip.h"
#include "Ships/ThreeDeckShip.h"
#include "Ships/FourDeckShip.h"

enum cell_state {SEA = 1, SHIP};
class BattleShipModel {
    private:
        std::string _game_mode;
        std::string _game_stage;

        bool _controller_changes;
        bool _window_changes;

        std::vector<Ship*> _ships {new SingleDeckShip(), new SingleDeckShip(), new SingleDeckShip(), new SingleDeckShip(),
                                  new DoubleDeckShip(), new DoubleDeckShip(), new DoubleDeckShip(),
                                  new ThreeDeckShip(),  new ThreeDeckShip(),
                                  new FourDeckShip()};

        int _current_ship;

        BattleShipMenuModel battleShipMenuModel;
    public:
        int down_count = 0, up_count = 0, right_count = 0, left_count = 0;
        explicit BattleShipModel(const std::string &game_mode) {
            _game_mode = game_mode;
            _game_stage = "Menu";

            _controller_changes = true;
            _window_changes = true;

            _current_ship = 0;
        }

        std::string &getGameMode() {
            return _game_mode;
        }

        std::string &getGameStage() {
            return _game_stage;
        }

        const bool &getControllerChanges() const{
            return _controller_changes;
        }

        const bool getWindowChanges() const{
            return _window_changes;
        }

        const std::vector<Ship*> &getShips() const  {
            return _ships;
        }

        int getCurrentShip() const{
            return _current_ship;
        }

        BattleShipMenuModel &getBattleShipMenuModel(){
            return battleShipMenuModel;
        }

        void setGameStage(std::string game_stage) {
            this->_game_stage = game_stage;
            _controller_changes = _window_changes = true;
        }

        void setControllerChanges(bool controller_changes) {
            this->_controller_changes = controller_changes;
        }

        void setWindowChanges(bool window_changes) {
            this->_window_changes = window_changes;
        }

        void setCurrentShip(int current_ship) {
            _current_ship = current_ship;
        }
};

#endif //LAB_3_BATTLESHIPMODEL_H
