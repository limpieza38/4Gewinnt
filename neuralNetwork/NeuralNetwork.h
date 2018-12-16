#ifndef INC_4GEWINNT_NEURAL_NETWORK_H
#define INC_4GEWINNT_NEURAL_NETWORK_H

#include "../PlayingField.h"

class NeuralNetwork
{
  private:
    // Gewichte
  public:
    NeuralNetwork(){};
    void train();
    int quest(PlayingField *playingField);
    void printWeightsToFile();
};

#endif //INC_4GEWINNT_NEURAL_NETWORK_H
