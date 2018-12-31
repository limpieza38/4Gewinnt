//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_NEURALNETWORKPLAYER_H
#define INC_4GEWINNT_NEURALNETWORKPLAYER_H

#include "Player.h"
#include "../PlayingField.h"
#include "../neuralNetwork/NeuralNetwork.h"

class NeuralNetworkPlayer : public Player
{
private:
  NeuralNetwork neuralNetwork;

public:
  int play(PlayingField *_playingField);
  NeuralNetworkPlayer(int name) : Player(name), neuralNetwork(NeuralNetwork(name))
  {
    neuralNetwork.loadWeights();
  };
  void train();
  void saveMove(std::array<std::array<int, 7>, 6> field, int column);
  void printStorageToFile();
};

#endif //INC_4GEWINNT_NEURALNETWORKPLAYER_H
