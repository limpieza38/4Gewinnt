#include <iostream>
#include "Player.h"
#include "PlayingField.h"
#include "RandomPlayer.h"
#include "GameMachine.h"


int main() {
    srand(time(0));
    RandomPlayer playerA;
    RandomPlayer playerB;
    GameMachine machine;
    int winner = machine.playAGame(&playerA, &playerB);
    return 0;
}


