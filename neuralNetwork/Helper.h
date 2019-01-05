#ifndef INC_4GEWINNT_NEURAL_HELPER_H
#define INC_4GEWINNT_NEURAL_HELPER_H

#include <array>
#include "NeuralNetwork.h"

class Helper
{
  public:
    static float sigmoid(float x);

    static std::array<float, HIDDEN_NODES> calculateHiddenInputs(std::array<float, INPUT_NODES> input,
                                                                 std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES> wih);

    static std::array<float, OUTPUT_NODES> calculateFinalInputs(std::array<float, HIDDEN_NODES> hidden,
                                                                std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who);

    static std::array<float, HIDDEN_NODES> calculateHiddenErrors(std::array<float, OUTPUT_NODES> outputErrors,
                                                                 std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who);

    static std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES>
    calculateNewWho(std::array<float, OUTPUT_NODES> outputErrors, std::array<float, OUTPUT_NODES> finalOutputs,
                    std::array<float, HIDDEN_NODES> hiddenOutputs,
                    std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who);

    static std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES>
    calculateNewWih(std::array<float, HIDDEN_NODES> hiddenErrors, std::array<float, HIDDEN_NODES> hiddenOutputs,
                    std::array<float, INPUT_NODES> inputs,
                    std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES> wih);
};

#endif //INC_4GEWINNT_NEURAL_HELPER_H
