#include <iostream>
#include "./Player/NeuralNetworkPlayer.h"
#include "GameMachine.h"
#include "Player/RandomPlayer.h"
#include "Player/CmdInputPlayer.h"
#include <ctime>

int main()
{
    srand(time(0));

    RandomPlayer player1(1);
    NeuralNetworkPlayer player2(2);
    GameMachine machine;

    for (int i = 0; i < 100000; i++)
    {
        player1 = RandomPlayer(1);
        player2 = RandomPlayer(2);
        cout << "Game #" << i + 1 << std::endl;
        Player *winner = machine.playAGame(&player1, &player2);
        if (winner == &player1)
        {
            player1.printStorageToFile();
        }
        else if (winner == &player2)
        {
            player2.printStorageToFile();
        }
    }

    return 0;
}
