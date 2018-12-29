#ifndef INC_4GEWINNT_NEURAL_NETWORK_H
#define INC_4GEWINNT_NEURAL_NETWORK_H

#define HIDDEN_NODES 20
#define INPUT_NODES 42
#define OUTPUT_NODES 7
#define LEARNING_RATE 0.3

#include "../PlayingField.h"
#include "../Player.h"
#include <array>

class NeuralNetwork
{
private:
    Player *player;
    std::array<float, OUTPUT_NODES> target;
    std::array<float, INPUT_NODES> input;
    std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES> wih;
    std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who;
    void loadWeightsFromFile(ifstream &weightsStorageFile);
    void initializeWeightsWithRandomNumbers();
    void loadNextTrainingLine(ifstream &trainStorageFile);
    void printWeightsToFile();
    void trainOneTrainingLine();

public:
    NeuralNetwork(Player *player)
    {
        this->player = player;
    };
    void train();
    int quest(PlayingField *playingField);
};

#endif //INC_4GEWINNT_NEURAL_NETWORK_H