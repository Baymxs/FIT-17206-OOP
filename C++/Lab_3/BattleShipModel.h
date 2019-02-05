//
// Created by Bayramov Nidjat on 16.11.18.
//

#ifndef LAB_3_BATTLESHIPMODEL_H
#define LAB_3_BATTLESHIPMODEL_H

#include <string>
#include <vector>
#include <random>
#include "BattleShipMenuModel.h"
#include "Ships/SingleDeckShip.h"
#include "Ships/DoubleDeckShip.h"
#include "Ships/ThreeDeckShip.h"
#include "Ships/FourDeckShip.h"
#include "RandomPlacement.h"

class BattleShipModel {
    private:
        std::string _game_mode;
        std::string _game_stage;

        bool _controller_changes;
        bool _window_changes;

        bool _is_game_started;

        int _player1, _player2;

        bool _player1_turn, _player2_turn;

        std::vector<Ship*> _player1_ships {new SingleDeckShip(), new SingleDeckShip(), new SingleDeckShip(), new SingleDeckShip(),
                                           new DoubleDeckShip(), new DoubleDeckShip(), new DoubleDeckShip(),
                                           new ThreeDeckShip(),  new ThreeDeckShip(),
                                           new FourDeckShip()};

        std::vector<Ship*> _player2_ships {new SingleDeckShip(), new SingleDeckShip(), new SingleDeckShip(), new SingleDeckShip(),
                                           new DoubleDeckShip(), new DoubleDeckShip(), new DoubleDeckShip(),
                                           new ThreeDeckShip(),  new ThreeDeckShip(),
                                           new FourDeckShip()};

        int _current_ship;

        std::vector<int> _ships_count;

        RandomPlacement randomPlacement;

        BattleShipMenuModel battleShipMenuModel;
    public:
        explicit BattleShipModel(const std::string &game_mode) {
            _game_mode = game_mode;
            _game_stage = "Menu";

            _controller_changes = true;
            _window_changes = true;

            _is_game_started = false;

            _player1 = 1;
            _player2 = 1;

            _player1_turn = true;
            _player2_turn = false;

            _current_ship = 0;

            _ships_count = {4, 3, 2, 1};
        }


        std::string &getGameMode() {
            return _game_mode;
        }

        std::string &getGameStage() {
            return _game_stage;
        }

        bool getControllerChanges() {
            return _controller_changes;
        }

        bool getWindowChanges() {
            return _window_changes;
        }

        int getPlayer1() {
            return _player1;
        }

        int getPlayer2() {
            return _player2;
        }

        const std::vector<Ship*> &getPlayer1Ships() const {
            return _player1_ships;
        }

        const std::vector<Ship*> &getPlayer2Ships() const {
            return _player2_ships;
        }

        bool isPlayer1Choice() const {
            return _player1_turn;
        }

        bool isPlayer2Choice() const {
            return _player2_turn;
        }

        int getCurrentShip() const{
            return _current_ship;
        }

        std::vector<int> &getShipsCount(){
            return _ships_count;
        }

        BattleShipMenuModel &getBattleShipMenuModel(){
            return battleShipMenuModel;
        }

        void setGameStage(const std::string &game_stage) {
            this->_game_stage = game_stage;
            _controller_changes = _window_changes = true;
        }

        void setControllerChanges(bool controller_changes) {
            this->_controller_changes = controller_changes;
        }

        void setWindowChanges(bool window_changes) {
            this->_window_changes = window_changes;
        }

        void setPlayer1(int player) {
            _player1 = player;
        }

        void setPlayer2(int player) {
            _player2 = player;
        }

        void setPlayer1Choice(bool player1_choice) {
            _player1_turn = player1_choice;
        }

        void setPlayer2Choice(bool player2_choice) {
            _player2_turn = player2_choice;
        }

        void setCurrentShip(int current_ship) {
            _current_ship = current_ship;
        }

        void setGameStartedState(bool state) {
            _is_game_started = state;
        }

        bool isGameStarted() {
            return _is_game_started;
        }

        bool isShipPlaced(int x, int y) {
            for (auto &_player1_ship : _player1_ships) {
                if (_player1_ship->getLocationState()) {
                    for (auto &j : _player1_ship->getDecks()) {
                        if (j.first == x && j.second == y) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        bool isAllShipsAreLocated1() {
            for (int i = 0; i < 10; i++) {
                if (!_player1_ships[i]->getLocationState()) {
                    return false;
                }
            }
            return true;
        }

        bool isAllShipsAreLocated2() {
            for (int i = 0; i < 10; i++) {
                if (!_player2_ships[i]->getLocationState()) {
                    return false;
                }
            }
            return true;
        }

        void setPlayer1ShipAvailability(int current_ship) {
            bool state1 = true, state2 = true;
            for (int i = 0; i < _player1_ships[_current_ship]->getDecks().size(); i++) {
                for (int j = 0; j < _player1_ships.size(); j++) {
                    if (j != current_ship && _player1_ships[j]->getLocationState()) {
                        for (int k = 0; k < _player1_ships[j]->getDecks().size(); k++) {
                            auto& decks1 = _player1_ships[_current_ship]->getDecks()[i];
                            auto& decks2 = _player1_ships[j]->getDecks()[k];
                                if (decks1 ==  decks2) {
                                    state1 = false;
                                }
                        }
                        for (int k = 0; k < _player1_ships[j]->getNearCells().size(); k++) {
                                if (_player1_ships[_current_ship]->getDecks()[i] ==
                                    _player1_ships[j]->getNearCells()[k]) {
                                    state2 = false;
                                }
                        }
                        _player1_ships[_current_ship]->setAvailabilityState(state1 && state2);
                    }
                }
            }
        }

        bool getPlayer1ShipAvailability(int current_ship) {
            for (int i = 0; i < _player1_ships[current_ship]->getDecks().size(); i++) {
                for (int j = 0; j < _player1_ships.size(); j++) {
                    if (j != current_ship && _player1_ships[j]->getLocationState()) {
                        for (int k = 0; k < _player1_ships[j]->getDecks().size(); k++) {
                            auto& deck1 = _player1_ships[current_ship]->getDecks()[i];
                            auto& deck2 = _player1_ships[j]->getDecks()[k];
                            if (deck1 == deck2) {
                                return false;
                            }
                        }
                        for (int k = 0; k < _player1_ships[j]->getNearCells().size(); k++) {
                            auto& deck11 = _player1_ships[current_ship]->getDecks()[i];
                            auto& deck22 = _player1_ships[j]->getNearCells()[k];
                            if (deck11 == deck22) {
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }

        void setPlayer2ShipAvailability(int current_ship) {
            bool state1 = true, state2 = true;
            for (int i = 0; i < _player2_ships[_current_ship]->getDecks().size(); i++) {
                for (int j = 0; j < _player2_ships.size(); j++) {
                    if (j != current_ship && _player2_ships[j]->getLocationState()) {
                        for (int k = 0; k < _player2_ships[j]->getDecks().size(); k++) {
                            if (_player2_ships[_current_ship]->getDecks()[i] == _player2_ships[j]->getDecks()[k]) {
                                state1 = false;
                            }
                        }
                        for (int k = 0; k < _player2_ships[j]->getNearCells().size(); k++) {
                            if (_player2_ships[_current_ship]->getDecks()[i] ==
                                _player2_ships[j]->getNearCells()[k]) {
                                state2 = false;
                            }
                        }
                        _player2_ships[_current_ship]->setAvailabilityState(state1 && state2);
                    }
                }
            }
        }

        void setRandomShipPlacement() {
            int random_rotation, random_placement;
            srand(static_cast<unsigned int>(time(nullptr)));

            setPlayer1Choice(false);

            for (int i = 0; i < 10; i++) {
                _player1_ships[i]->getDecks().clear();
                _player1_ships[i]->setNearCells();
            }

            for (int &i : _ships_count) {
                i = 0;
            }

            for (int i = 0; i < _player1_ships.size(); i++) {
                if (i < 4) {
                    while (true) {
                        random_placement = rand() % 100;

                        _player1_ships[i]->getDecks().push_back(randomPlacement.getOneDeckShipRandomPlacement()[random_placement]);
                        _player1_ships[i]->setNearCells();


                        if (getPlayer1ShipAvailability(i)) {
                            break;
                        } else {
                            _player1_ships[i]->getDecks().clear();
                        }
                    }
                    _player1_ships[i]->setLocationState(true);
                } else if (i >= 4 && i <= 6) {
                    while (true) {
                        random_rotation = rand() % 2;
                        random_placement = rand() % 81;

                        if (random_rotation) {
                            _player1_ships[i]->getDecks().push_back(randomPlacement.getHorizontalTwoDeckShipRandomPlacement()[random_placement].first);
                            _player1_ships[i]->getDecks().push_back(randomPlacement.getHorizontalTwoDeckShipRandomPlacement()[random_placement].second);
                        } else {
                            _player1_ships[i]->setVerticalRotationName();
                            _player1_ships[i]->getDecks().push_back(randomPlacement.getVerticalTwoDeckShipRandomPlacement()[random_placement].first);
                            _player1_ships[i]->getDecks().push_back(randomPlacement.getVerticalTwoDeckShipRandomPlacement()[random_placement].second);
                        }
                        _player1_ships[i]->setNearCells();

                        if (getPlayer1ShipAvailability(i)) {
                            break;
                        } else {
                            _player1_ships[i]->getDecks().clear();
                        }
                    }
                    _player1_ships[i]->setLocationState(true);
                } else if (i >= 7 && i <= 8) {
                    while (true) {
                        random_rotation = rand() % 2;
                        random_placement = rand() % 64;

                        if (random_rotation) {
                            _player1_ships[i]->getDecks().push_back(std::get<0>(randomPlacement.getHorizontalThreeDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<1>(randomPlacement.getHorizontalThreeDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<2>(randomPlacement.getHorizontalThreeDeckShipRandomPlacement()[random_placement]));
                        } else {
                            _player1_ships[i]->setVerticalRotationName();
                            _player1_ships[i]->getDecks().push_back(std::get<0>(randomPlacement.getVerticalThreeDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<1>(randomPlacement.getVerticalThreeDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<2>(randomPlacement.getVerticalThreeDeckShipRandomPlacement()[random_placement]));
                        }
                        _player1_ships[i]->setNearCells();

                        if (getPlayer1ShipAvailability(i)) {
                            break;
                        } else {
                            _player1_ships[i]->getDecks().clear();
                        }
                    }
                    _player1_ships[i]->setLocationState(true);
                } else if (i == 9) {
                    while (true) {
                        random_rotation = rand() % 2;
                        random_placement = rand() % 49;

                        if (random_rotation) {
                            _player1_ships[i]->getDecks().push_back(std::get<0>(randomPlacement.getHorizontalFourDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<1>(randomPlacement.getHorizontalFourDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<2>(randomPlacement.getHorizontalFourDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<3>(randomPlacement.getHorizontalFourDeckShipRandomPlacement()[random_placement]));
                        } else {
                            _player1_ships[i]->setVerticalRotationName();
                            _player1_ships[i]->getDecks().push_back(std::get<0>(randomPlacement.getVerticalFourDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<1>(randomPlacement.getVerticalFourDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<2>(randomPlacement.getVerticalFourDeckShipRandomPlacement()[random_placement]));
                            _player1_ships[i]->getDecks().push_back(std::get<3>(randomPlacement.getVerticalFourDeckShipRandomPlacement()[random_placement]));
                        }
                        _player1_ships[i]->setNearCells();

                        if (getPlayer1ShipAvailability(i)) {
                            break;
                        } else {
                            _player1_ships[i]->getDecks().clear();
                        }
                    }
                    _player1_ships[i]->setLocationState(true);
                }
            }
        }
};

#endif //LAB_3_BATTLESHIPMODEL_H
