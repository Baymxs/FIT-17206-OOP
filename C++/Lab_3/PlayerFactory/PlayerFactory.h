//
// Created by Bayramov Nidjat on 28.12.18.
//

#ifndef LAB_3_PLAYERFACTORY_H
#define LAB_3_PLAYERFACTORY_H

#include <map>
#include <string>
#include <exception>

#include "PlayerCreator.h"
#include "Player.h"

class PlayerFactory {
private:
    //We placed the constructor in a private area so that it was impossible to create objects of type PlayerFactory
    //We can't use "new" keyword
    PlayerFactory() = default;

    //Create a container "map" that stores PlayerCreators.
    std::map<std::string, PlayerCreator*> players;

public:
    virtual ~PlayerFactory() {
        for (auto item : players) {
            delete item.second;
        }
    };

    static PlayerFactory& getInstance() {
        //Variable playerFactory of type PlayerFactory will be in the static memory area only after calling the method
        static PlayerFactory playerFactory;
        return playerFactory;
    }

    Player* getPlayer(BattleShipModel *battleShipModel) {
        auto it = players.find(battleShipModel->getGameMode());
        if (it == players.end()) {}
        return  it->second->create(battleShipModel);
    }

    void registerPlayer(const std::string &player_name, PlayerCreator *creator) {
        //We find the item from map-container "players" with "player_name" key
        auto it = players.find(player_name);
        //If the map-container already has an item with key "player_name"
        if (it != players.end()) {
            //If the value of item we found is the creator that we gave to the function as an argument return
            if (it->second == creator) return;
            else delete it->second;
        }
        players[player_name] = creator;
    }
};

#endif //LAB_3_PLAYERFACTORY_H
