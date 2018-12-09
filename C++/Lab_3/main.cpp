#include "BattleShip.h"

int main(int argc, char *argv[]) {
    BattleShip *battleShip = new BattleShip(argv[1]);
    battleShip->startGame();
}