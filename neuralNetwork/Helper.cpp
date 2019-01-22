#include "Helper.h"

#include <math.h>

float Helper::sigmoid(float x)
{
    float exp_value = exp((double)-x);
    float return_value = 1 / (1 + exp_value);
    return return_value;
}

std::array<float, HIDDEN_NODES> Helper::calculateHiddenInputs(std::array<float, INPUT_NODES> input, std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES> wih)
{
    std::array<float, HIDDEN_NODES> hiddenInputs;
    for (int hnId = 0; hnId < HIDDEN_NODES; hnId++)
    {
        hiddenInputs[hnId] = 0;
        for (int inId = 0; inId < INPUT_NODES; inId++)
        {
            hiddenInputs[hnId] += input[inId] * wih[inId][hnId];
        }
    }
    return hiddenInputs;
};

std::array<float, OUTPUT_NODES> Helper::calculateFinalInputs(std::array<float, HIDDEN_NODES> hidden,
                                                             std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who)
{
    std::array<float, OUTPUT_NODES> finalInputs;
    for (int outId = 0; outId < OUTPUT_NODES; outId++)
    {
        finalInputs[outId] = 0;
        for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
        {
            finalInputs[outId] += hidden[hiId] * who[hiId][outId];
        }
    }
    return finalInputs;
};

std::array<float, HIDDEN_NODES> Helper::calculateHiddenErrors(std::array<float, OUTPUT_NODES> outputErrors,
                                                              std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who)
{

    std::array<float, HIDDEN_NODES> hiddenErrors;
    for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
    {
        hiddenErrors[hiId] = 0;
        for (int outId = 0; outId < HIDDEN_NODES; outId++)
        {

            hiddenErrors[hiId] += outputErrors[outId] * who[hiId][outId];
        }
    }
    return hiddenErrors;
}

std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> Helper::calculateNewWho(
    std::array<float, OUTPUT_NODES> outputErrors, std::array<float, OUTPUT_NODES> finalOutputs,
    std::array<float, HIDDEN_NODES> hiddenOutputs,
    std::array<std::array<float, OUTPUT_NODES>, HIDDEN_NODES> who)
{
    float errorFactor;
    for (int outId = 0; outId < OUTPUT_NODES; outId++)
    {
        errorFactor = outputErrors[outId] * finalOutputs[outId] * (1.00f - finalOutputs[outId]);
        for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
        {
            who[hiId][outId] += LEARNING_RATE * errorFactor * hiddenOutputs[hiId];
        }
    }
    return who;
}

std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES> Helper::calculateNewWih(
    std::array<float, HIDDEN_NODES> hiddenErrors, std::array<float, HIDDEN_NODES> hiddenOutputs,
    std::array<float, INPUT_NODES> inputs, std::array<std::array<float, HIDDEN_NODES>, INPUT_NODES> wih)
{
    float errorFactor;
    for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
    {
        errorFactor = hiddenErrors[hiId] * hiddenOutputs[hiId] * (1.00f - hiddenOutputs[hiId]);
        for (int inId = 0; inId < INPUT_NODES; inId++)
        {
            wih[inId][hiId] += LEARNING_RATE * errorFactor * inputs[inId];
        }
    }
    return wih;
}
