//
// Created by Bayramov Nidjat on 22.12.18.
//

#ifndef LAB_3_SHIP_H
#define LAB_3_SHIP_H

#include <string>
#include <map>
#include <vector>

class Ship {
    private:
        std::vector<std::pair<int, int>> _decks;
        std::vector<std::pair<int, int>> _near_cells;

        std::string _rotation;

        bool _is_located;
        bool _is_availability;

    public:
        Ship() {
            _rotation = "horizontal";

            _is_located = false;
            _is_availability = true;
        }

        std::string getRotation() {
            return _rotation;
        }

        bool getLocationState() const{
            return _is_located;
        }

        bool getAvailabilityState() const{
            return _is_availability;
        }

        std::vector<std::pair<int, int>> &getDecks() {
            return _decks;
        }

        std::vector<std::pair<int, int>> &getNearCells() {
            return _near_cells;
        }

        bool isDeck(int x, int y) {
            for (auto &_deck : _decks) {
                if (x == _deck.first && y == _deck.second) {
                    return true;
                }
            }
            return false;
        }

        void setNearCells() {
            getNearCells().clear();

            if (!getDecks().empty()) {
                int x = getDecks()[0].first - 1;
                int y = getDecks()[0].second - 1;

                getNearCells().clear();

                if (getRotation() == "horizontal") {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < getDecks().size() + 2; j++) {
                            if (!isDeck(x + j, y + i)) {
                                getNearCells().emplace_back(x + j, y + i);
                            }
                        }
                    }
                } else if (getRotation() == "vertical") {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < getDecks().size() + 2; j++) {
                            if (!isDeck(x + i, y + j)) {
                                getNearCells().emplace_back(x + i, y + j);
                            }
                        }
                    }
                }
            }
        }

        void setLocationState(bool location_state) {
            _is_located = location_state;
        }

        void setAvailabilityState(bool availability_state) {
            _is_availability = availability_state;
        }

        void setHorizontalRotation() {
            if ((getDecks()[getDecks().size() - 1].first + getDecks().size() - 1) < 10) {
                _rotation = "horizontal";
                for (int i = 1; i < _decks.size(); i++) {
                    _decks[i].second = _decks[0].second;
                    _decks[i].first = _decks[0].first + i;
                }
            }
        }

        void setVerticalRotationName() {
            _rotation = "vertical";
        }

        void setVerticalRotation() {
            if ((getDecks()[getDecks().size() - 1].second + getDecks().size() - 1) < 10) {
                _rotation = "vertical";
                for (int i = 1; i < _decks.size(); i++) {
                    _decks[i].first = _decks[0].first;
                    _decks[i].second = _decks[0].second + i;
                }
            }
        }

        void changeRotation() {
            if (_rotation == "horizontal") {
                setVerticalRotation();
            } else if (_rotation == "vertical"){
                setHorizontalRotation();
            }
            setNearCells();
        }

        bool rightDecksShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.first == 9) {
                    return false;
                }
            }
            return true;
        }

        bool rightNCellsShearPossibility() {
            for (auto &cell : _near_cells) {
                if (cell.first == 10) {
                    return false;
                }
            }
            return true;
        }

        bool leftDecksShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.first == 0) {
                    return false;
                }
            }
            return true;
        }

        bool leftNCellsShearPossibility() {
            for (auto &cell : _near_cells) {
                if (cell.first == -1) {
                    return false;
                }
            }
            return true;
        }

        bool downDecksShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.second == 9) {
                    return false;
                }
            }
            return true;
        }

        bool downNCellsShearPossibility() {
            for (auto &cell : _near_cells) {
                if (cell.second == 10) {
                    return false;
                }
            }
            return true;
        }

        bool upDecksShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.second == 0) {
                    return false;
                }
            }
            return true;
        }

        bool upNCellsShearPossibility() {
            for (auto &cell : _near_cells) {
                if (cell.second == -1) {
                    return false;
                }
            }
            return true;
        }

        void rightShift() {
            for (auto &deck : _decks) {
                deck.first = deck.first + 1;
            }
            if (rightNCellsShearPossibility()) {
                for (auto &cell : _near_cells) {
                    cell.first = cell.first + 1;
                }
            }
        }

        void leftShift() {
            for (auto &deck : _decks) {
                deck.first = deck.first - 1;
            }
            if (leftNCellsShearPossibility()) {
                for (auto &cell : _near_cells) {
                    cell.first = cell.first - 1;
                }
            }
        }

        void downShift() {
            for (auto &deck : _decks) {
                deck.second = deck.second + 1;
            }
            if (downNCellsShearPossibility()) {
                for (auto &cell : _near_cells) {
                    cell.second = cell.second + 1;
                }
            }
        }

        void upShift() {
            for (auto &deck : _decks) {
                deck.second = deck.second - 1;
            }
            if (upNCellsShearPossibility()) {
                for (auto &cell : _near_cells) {
                    cell.second = cell.second - 1;
                }
            }
        }
};

#endif //LAB_3_SHIP_H
