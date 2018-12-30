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
  string folderName;
  std::array<float, OUTPUT_NODES> target;
  std::array<float, INPUT_NODES> input;
  std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES> wih;
  std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who;
  void initializeWeights();
  void loadWeightsFromFile(ifstream &weightsStorageFile);
  void initializeWeightsWithRandomNumbers();
  void loadNextTrainingLine(ifstream &trainStorageFile);
  void printWeightsToFile();
  void trainOneTrainingLine();

public:
  NeuralNetwork(string folderName);
  void train();
  std::array<float, 7> quest(std::array<int, INPUT_NODES> input);
};

#endif //INC_4GEWINNT_NEURAL_NETWORK_H