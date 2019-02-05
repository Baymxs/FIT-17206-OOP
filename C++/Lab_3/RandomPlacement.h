//
// Created by Bayramov Nidjat on 08.01.19.
//

#ifndef LAB_3_RANDOMPLACEMENT_H
#define LAB_3_RANDOMPLACEMENT_H

#include <vector>

class RandomPlacement {
    private:
        std::vector<std::pair<int, int>> one_deck_ship_random_placement;
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> horizontal_two_deck_ship_random_placement, vertical_two_deck_ship_random_placement;
        std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>>> horizontal_three_deck_ship_random_placement, vertical_three_deck_ship_random_placement;
        std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>, std::pair<int, int>>> horizontal_four_deck_ship_random_placement, vertical_four_deck_ship_random_placement;

        void setOneDeckShipRandomPlacement() {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    one_deck_ship_random_placement.emplace_back(std::make_pair(i, j));
                 }
            }
        }

        void setTwoDeckShipRandomPlacement() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    horizontal_two_deck_ship_random_placement.emplace_back(std::make_pair(j, i), std::make_pair(j + 1, i));
                    vertical_two_deck_ship_random_placement.emplace_back(std::make_pair(i, j), std::make_pair(i, j + 1));
                }
            }
        }

        void setThreeDeckShipRandomPlacement() {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    horizontal_three_deck_ship_random_placement.emplace_back(std::make_pair(j, i), std::make_pair(j + 1, i), std::make_pair(j + 2, i));
                    vertical_three_deck_ship_random_placement.emplace_back(std::make_pair(i, j), std::make_pair(i, j + 1), std::make_pair(i, j + 2));
                }
            }
        }

        void setFourDeckShipRandomPlacement() {
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    horizontal_four_deck_ship_random_placement.emplace_back(std::make_pair(j, i), std::make_pair(j + 1, i), std::make_pair(j + 2, i), std::make_pair(j + 3, i));
                    vertical_four_deck_ship_random_placement.emplace_back(std::make_pair(i, j), std::make_pair(i, j + 1), std::make_pair(i, j + 2), std::make_pair(i, j + 3));
                }
            }
        }

    public:
        RandomPlacement() {
            setOneDeckShipRandomPlacement();
            setTwoDeckShipRandomPlacement();
            setThreeDeckShipRandomPlacement();
            setFourDeckShipRandomPlacement();
        }

    std::vector<std::pair<int, int>> &getOneDeckShipRandomPlacement() {
        return one_deck_ship_random_placement;
    }

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> &getHorizontalTwoDeckShipRandomPlacement() {
        return horizontal_two_deck_ship_random_placement;
    }

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> &getVerticalTwoDeckShipRandomPlacement() {
        return vertical_two_deck_ship_random_placement;
    }

    std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>>> &getHorizontalThreeDeckShipRandomPlacement() {
        return horizontal_three_deck_ship_random_placement;
    }

    std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>>> &getVerticalThreeDeckShipRandomPlacement() {
        return vertical_three_deck_ship_random_placement;
    }

    std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>, std::pair<int, int>>> &getHorizontalFourDeckShipRandomPlacement() {
        return horizontal_four_deck_ship_random_placement;
    }

    std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::pair<int, int>, std::pair<int, int>>> &getVerticalFourDeckShipRandomPlacement() {
        return vertical_four_deck_ship_random_placement;
    }
};


#endif //LAB_3_RANDOMPLACEMENT_H
