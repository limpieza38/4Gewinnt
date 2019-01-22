#include <iostream>
#include <fstream>
#include "NeuralNetwork.h"
#include "Helper.h"

using namespace std;

void NeuralNetwork::train()
{
    cout << "TRAINING:" << std::endl;

    for (int epoch = 0; epoch < EPOCHS; epoch++)
    {
        cout << "EPOCH " << epoch << std::endl;
        loadWeights();

        ifstream trainStorageFile;
        string filename = "./player" + to_string(this->playerName) + "/train_data.txt";
        trainStorageFile.open(filename);
        if (trainStorageFile)
        {
            while (!trainStorageFile.eof())
            {
                cout << "Loading next training data line..." << std::endl;
                this->loadNextTrainingLine(trainStorageFile);
                cout << "Training with next training data line..." << std::endl;
                this->trainOneTrainingLine();
            }
            trainStorageFile.close();
        }
        else
            cout << "ERROR: Unable to open training data file" << std::endl;

        this->printWeightsToFile();
    }
}

void NeuralNetwork::loadWeights()
{
    // Initialize weights or read from file if exists
    string weightsStorageFileName = "./player" + to_string(this->playerName) + "/weights.txt";
    ifstream weightsStorageFile(weightsStorageFileName);
    if (weightsStorageFile.good())
    {
        // Read weights from file
        if (weightsStorageFile)
        {
            this->loadWeightsFromFile(weightsStorageFile);
            weightsStorageFile.close();
        }
        else
            cout << "ERROR: Unable to read weights from file" << std::endl;
    }
    else
    {
        // Initialize weights with random numbers
        this->initializeWeightsWithRandomNumbers();
    }
}

void NeuralNetwork::trainOneTrainingLine()
{
    std::array<float, HIDDEN_NODES> hiddenInputs = Helper::calculateHiddenInputs(this->input, this->wih);
    std::array<float, HIDDEN_NODES> hiddenOutputs;
    for (int i = 0; i < HIDDEN_NODES; i++)
    {
        hiddenOutputs[i] = Helper::sigmoid(hiddenInputs[i]);
    }
    std::array<float, OUTPUT_NODES> finalInputs = Helper::calculateFinalInputs(hiddenOutputs, this->who);
    std::array<float, OUTPUT_NODES> finalOutputs;
    for (int i = 0; i < OUTPUT_NODES; i++)
    {
        finalOutputs[i] = Helper::sigmoid(finalInputs[i]);
    }

    std::array<float, OUTPUT_NODES> outputErrors;
    for (int i = 0; i < OUTPUT_NODES; i++)
    {
        outputErrors[i] = this->target[i] - finalOutputs[i];
    }

    std::array<float, HIDDEN_NODES> hiddenErrors = Helper::calculateHiddenErrors(outputErrors, this->who);

    this->who = Helper::calculateNewWho(outputErrors, finalOutputs, hiddenOutputs, this->who);
    this->wih = Helper::calculateNewWih(hiddenErrors, hiddenOutputs, this->input, this->wih);
}

void NeuralNetwork::loadWeightsFromFile(ifstream &weightsStorageFile)
{
    cout << "Reading weights from file..." << std::endl;
    for (int inId = 0; inId < INPUT_NODES; inId++)
    {
        for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
        {
            weightsStorageFile >> this->wih[inId][hiId];
        }
    }
    for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
    {
        for (int outId = 0; outId < OUTPUT_NODES; outId++)
        {
            weightsStorageFile >> this->who[hiId][outId];
        }
    }
}

void NeuralNetwork::initializeWeightsWithRandomNumbers()
{
    cout << "Initializing weights with random numbers..." << std::endl;
    for (int inID = 0; inID < INPUT_NODES; inID++)
    {
        for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
        {
            this->wih[inID][hiId] = ((float)rand()) / RAND_MAX - 0.5f;
        }
    }
    for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
    {
        for (int outId = 0; outId < OUTPUT_NODES; outId++)
        {
            this->who[hiId][outId] = ((float)rand()) / RAND_MAX - 0.5f;
        }
    }
    this->printWeightsToFile();
}

void NeuralNetwork::loadNextTrainingLine(ifstream &trainStorageFile)
{
    for (int i = 0; i < OUTPUT_NODES; i++)
    {
        trainStorageFile >> this->target[i];
    }
    char separarator;
    trainStorageFile >> separarator;
    for (int i = 0; i < INPUT_NODES; i++)
    {
        trainStorageFile >> this->input[i];
        this->input[i] = transformInput(this->input[i]);
    }
}

float NeuralNetwork::transformInput(float value)
{
    return (value / (float)POSSIBLE_VALUES) * 0.99f + 0.01f;
}

void NeuralNetwork::printWeightsToFile()
{
    cout << "Writing weights to file..." << std::endl;
    ofstream storageFile;
    string filename = "./player" + to_string(this->playerName) + "/weights.txt";
    storageFile.open(filename);
    if (storageFile)
    {
        for (int inId = 0; inId < INPUT_NODES; inId++)
        {
            for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
            {
                storageFile << this->wih[inId][hiId] << " ";
            }
            storageFile << std::endl;
        }
        storageFile << std::endl;
        for (int hiId = 0; hiId < HIDDEN_NODES; hiId++)
        {
            for (int outId = 0; outId < OUTPUT_NODES; outId++)
            {
                storageFile << this->who[hiId][outId] << " ";
            }
            storageFile << std::endl;
        }
        storageFile.close();
    }
    else
        cout << "ERROR: Unable to write weights to file" << std::endl;
}

int NeuralNetwork::quest(std::array<int, INPUT_NODES> input)
{
    for (int i = 0; i < INPUT_NODES; i++)
    {
        this->input[i] = this->transformInput(input[i]);
    }
    std::array<float, HIDDEN_NODES> hiddenInputs = Helper::calculateHiddenInputs(this->input, this->wih);
    std::array<float, HIDDEN_NODES> hiddenOutputs;
    for (int i = 0; i < HIDDEN_NODES; i++)
    {
        hiddenOutputs[i] = Helper::sigmoid(hiddenInputs[i]);
    }
    std::array<float, OUTPUT_NODES> finalInputs = Helper::calculateFinalInputs(hiddenOutputs, this->who);
    std::array<float, OUTPUT_NODES> finalOutputs;
    for (int i = 0; i < OUTPUT_NODES; i++)
    {
        finalOutputs[i] = Helper::sigmoid(finalInputs[i]);
    }
    int highestTargetColumn = 0;
    for (int i = 1; i < OUTPUT_NODES; i++)
    {
        if (finalOutputs[highestTargetColumn] < finalOutputs[i])
        {
            highestTargetColumn = i;
        }
    }
    return highestTargetColumn;
}

std::array<float, OUTPUT_NODES> NeuralNetwork::questArray(std::array<int, INPUT_NODES> input)
{
    for (int i = 0; i < INPUT_NODES; i++)
    {
        this->input[i] = this->transformInput(input[i]);
    }
    std::array<float, HIDDEN_NODES> hiddenInputs = Helper::calculateHiddenInputs(this->input, this->wih);
    std::array<float, HIDDEN_NODES> hiddenOutputs;
    for (int i = 0; i < HIDDEN_NODES; i++)
    {
        hiddenOutputs[i] = Helper::sigmoid(hiddenInputs[i]);
    }
    std::array<float, OUTPUT_NODES> finalInputs = Helper::calculateFinalInputs(hiddenOutputs, this->who);
    std::array<float, OUTPUT_NODES> finalOutputs;
    for (int i = 0; i < OUTPUT_NODES; i++)
    {
        finalOutputs[i] = Helper::sigmoid(finalInputs[i]);
    }
    return finalOutputs;
}
