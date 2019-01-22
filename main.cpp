#include <iostream>
#include "./Player/NeuralNetworkPlayer.h"
#include "./Player/CmdInputPlayer.h"
#include "GameMachine.h"
#include <ctime>
#include <fstream>

int main()
{
    srand(time(0));

    //
    // Two neural networks against each other:
    //

    NeuralNetworkPlayer player1(1);
    NeuralNetworkPlayer player2(2);
    GameMachine machine;

    int countPlayer1Wins = 0;
    int countPlayer2Wins = 0;
    const int numberOfGames = 100;

    for (int i = 0; i < numberOfGames; i++)
    {
        cout << "Game #" << i + 1 << std::endl;
        Player *winner = machine.playAGame(&player1, &player2);
        if (winner == &player1)
        {
            countPlayer1Wins++;
            player2.printStorageToFile();
            player2.train();
        }
        else if (winner == &player2)
        {
            countPlayer2Wins++;
            player1.printStorageToFile();
            player1.train();
        }
    }

    float percentagePlayer1Wins = (float)countPlayer1Wins / (float)numberOfGames * 100.0;
    float percentagePlayer2Wins = (float)countPlayer2Wins / (float)numberOfGames * 100.0;
    float percentageRemis = 100.0 - percentagePlayer1Wins - percentagePlayer2Wins;

    cout << std::endl
         << "Result:" << std::endl;
    cout << "Number of games: " << numberOfGames << std::endl;
    cout << "Player 1: " << percentagePlayer1Wins << "%" << std::endl;
    cout << "Player 2: " << percentagePlayer2Wins << "%" << std::endl;
    cout << "Remis: " << percentageRemis << "%" << std::endl;

    //
    // CMD player against neural network:
    //

    // NeuralNetworkPlayer player1(1);
    // CmdInputPlayer player2(2);
    // GameMachine machine;

    // machine.playAGame(&player1, &player2);

    //
    // Test neural network with MNIST data:
    //

    // NeuralNetwork neuralNetwork(3);
    // neuralNetwork.train();

    // cout << "Testing..." << std::endl;

    // int right = 0;
    // int wrong = 0;

    // ifstream testStorageFile;
    // string filename = "./player3/test_data.txt";
    // testStorageFile.open(filename);
    // if (testStorageFile)
    // {
    //     while (!testStorageFile.eof())
    //     {
    //         int target;
    //         std::array<int, 784> input;
    //         char separator;

    //         testStorageFile >> target;
    //         for (int i = 0; i < 784; i++)
    //         {
    //             testStorageFile >> separator;
    //             testStorageFile >> input[i];
    //         }
    //         int result = neuralNetwork.quest(input);
    //         if (result == target)
    //         {
    //             right++;
    //         }
    //         else
    //         {
    //             wrong++;
    //         }
    //     }
    //     testStorageFile.close();

    //     float percentageRight = ((float)right / ((float)right + (float)wrong)) * 100.0;

    //     cout << std::endl
    //          << "Result:" << std::endl;
    //     cout << "Right: " << percentageRight << "%" << std::endl;
    // }
    // else
    //     cout << "ERROR: Unable to open test data file" << std::endl;

    return 0;
}
