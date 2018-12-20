#include <iostream>
#include "Player.h"
#include "PlayingField.h"
#include "RandomPlayer.h"
#include "GameMachine.h"
#include <ctime>
#include "./neuralNetwork/NeuralNetwork.h"

int main()
{
    srand(time(0));

    RandomPlayer player1(1);
    RandomPlayer player2(2);

    // Generate Training Data
    GameMachine machine;
    Player *winner = machine.playAGame(&player1, &player2);
    winner->printStorageToFile();

    std::cout << std::endl;

    // Train The Neural Network
    NeuralNetwork neuralNetwork(&player1);
    neuralNetwork.train();

    return 0;
}
