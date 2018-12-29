#ifndef INC_4GEWINNT_NEURAL_NETWORK_H
#define INC_4GEWINNT_NEURAL_NETWORK_H

#define HIDDEN_NODES 20
#define LEARNING_RATE 0.3

#include "../PlayingField.h"
#include "../Player.h"
#include <array>

class NeuralNetwork
{
private:
    Player *player;
    std::array<float, 7> target;
    std::array<int, 42> input;
    std::array<std::array<float, 42>, HIDDEN_NODES> weights1;
    std::array<std::array<float, HIDDEN_NODES>, 7> weights2;
    void loadWeightsFromFile(ifstream &weightsStorageFile);
    void initializeWeightsWithRandomNumbers();
    void loadNextTrainingLine(ifstream &trainStorageFile);
    void printWeightsToFile();

public:
    NeuralNetwork(Player *player)
    {
        this->player = player;
    };
    void train();
    int quest(PlayingField *playingField);
};

#endif //INC_4GEWINNT_NEURAL_NETWORK_H