#include <iostream>
#include "./Player/NeuralNetworkPlayer.h"
#include "GameMachine.h"
#include <ctime>

int main()
{
    srand(time(0));

    NeuralNetworkPlayer player1(1);
    NeuralNetworkPlayer player2(2);
    GameMachine machine;

    for (int i = 0; i < 100; i++)
    {
        cout << "Game #" << i + 1 << std::endl;
        Player *winner = machine.playAGame(&player1, &player2);
        if (winner == &player1)
        {
            player2.printStorageToFile();
            player2.train();
        }
        else if (winner == &player2)
        {
            player1.printStorageToFile();
            player1.train();
        }
    }

    return 0;
}
