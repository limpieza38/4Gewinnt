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
    RandomPlayer playerA(1);
    RandomPlayer playerB(2);
    GameMachine machine;
    Player *winner = machine.playAGame(&playerA, &playerB);
    winner->printStorageToFile();

    NeuralNetwork neuralNetwork;
    neuralNetwork.train();
    neuralNetwork.printWeightsToFile();

    return 0;
}
