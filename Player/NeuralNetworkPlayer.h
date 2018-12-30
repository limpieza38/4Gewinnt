//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_NEURALNETWORKPLAYER_H
#define INC_4GEWINNT_NEURALNETWORKPLAYER_H

#include "Player.h"
#include "../neuralNetwork/NeuralNetwork.h"

class NeuralNetworkPlayer : public Player
{
  private:
    NeuralNetwork neuralNetwork;
    std::array<float, INPUT_NODES> transformFieldToInput(PlayingField * playingField);
  public:
    int play(PlayingField *);
    NeuralNetworkPlayer(int name) : Player(name), neuralNetwork(NeuralNetwork(name)) {
        neuralNetwork.loadWeights();
    };
};

#endif //INC_4GEWINNT_NEURALNETWORKPLAYER_H
