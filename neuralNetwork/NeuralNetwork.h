#ifndef INC_4GEWINNT_NEURAL_NETWORK_H
#define INC_4GEWINNT_NEURAL_NETWORK_H

#define HIDDEN_NODES 200  // 10
#define INPUT_NODES 42    // 784
#define OUTPUT_NODES 7    // 10
#define LEARNING_RATE 0.3 // 0.1
#define POSSIBLE_VALUES 2 // 255
#define EPOCHS 1          // 5

#include <fstream>
#include <array>

using namespace std;
class NeuralNetwork
{
private:
  int playerName;
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
  void loadWeights();
  NeuralNetwork(int playerName)
  {
    this->playerName = playerName;
  };
  void train();
  int quest(std::array<int, INPUT_NODES> input);
  float transformInput(float value);
  std::array<float, OUTPUT_NODES> questArray(std::array<int, INPUT_NODES> input);
};

#endif //INC_4GEWINNT_NEURAL_NETWORK_H
