#ifndef INC_4GEWINNT_NNPLAYER_H
#define INC_4GEWINNT_NNPLAYER_H

#include <random>
#include "Player.h"
#include "./neuralNetwork/NeuralNetwork.h"

class NNPlayer : public Player
{
  private:
    NeuralNetwork *neuralNetwork;
    float lastMax;
    std::array<float, 7> lastOutputs;

  public:
    int play(PlayingField *);
    int chooseOtherColumn();
    NNPlayer(int name) : Player(name)
    {
        this->neuralNetwork = new NeuralNetwork("player" + to_string(name));
    };
    ~NNPlayer()
    {
        delete this->neuralNetwork;
    }
    void printStorageToFile();
    void train();
    void saveMove(std::array<std::array<int, 7>, 6> field, int column);
};

#endif //INC_4GEWINNT_NNPLAYER_H
