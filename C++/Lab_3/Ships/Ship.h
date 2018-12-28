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
        bool _is_located;
        bool _is_destroyed;
        std::string _rotation;

        bool rightShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.first == 9) {
                    return false;
                }
            }
            return true;
        }

        bool leftShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.first == 0) {
                    return false;
                }
            }
            return true;
        }

        bool downShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.second == 9) {
                    return false;
                }
            }
            return true;
        }

        bool upShearPossibility() {
            for (auto &deck : _decks) {
                if (deck.second == 0) {
                    return false;
                }
            }
            return true;
        }
    public:
        Ship() {
            _rotation = "horizontal";
            _is_located = false;
            _is_destroyed = false;
        }

        void setRotation(const std::string &rotation) {
            _rotation = rotation;
        }

        std::vector<std::pair<int, int>> &getDecks() {
            return _decks;
        }

        const std::string &getRotation() const {
            return _rotation;
        }

        void rightShift() {
            if (rightShearPossibility()) {
                for (auto &deck : _decks) {
                    deck.first = deck.first + 1;
                }
            }
        }

        void leftShift() {
            if (leftShearPossibility()) {
                for (auto &deck : _decks) {
                    deck.first = deck.first - 1;
                }
            }
        }

        void downShift() {
            if (downShearPossibility()) {
                for (auto &deck : _decks) {
                    deck.second = deck.second + 1;
                }
            }
        }

        void upShift() {
            if (upShearPossibility()) {
                for (auto &deck : _decks) {
                    deck.second = deck.second - 1;
                }
            }
        }
};

#endif //LAB_3_SHIP_H
