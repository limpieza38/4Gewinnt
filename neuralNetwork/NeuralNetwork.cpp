#include <iostream>
#include <fstream>
#include "NeuralNetwork.h"
#include "Helper.h"

using namespace std;

NeuralNetwork::NeuralNetwork(string folderName)
{
    this->folderName = folderName;
    this->initializeWeights();
    this->printWeightsToFile();
};

void NeuralNetwork::train()
{
    cout << "TRAINING:" << std::endl;

    this->initializeWeights();

    ifstream trainStorageFile;
    string filename = "./" + this->folderName + "/train_data.txt";
    trainStorageFile.open(filename);
    if (trainStorageFile)
    {
        while (!trainStorageFile.eof())
        {
            cout << "Training with next training data line..." << std::endl;
            this->loadNextTrainingLine(trainStorageFile);
            this->trainOneTrainingLine();
        }
        trainStorageFile.close();
    }
    else
        cout << "ERROR: Unable to open training data file" << std::endl;

    this->printWeightsToFile();
}

void NeuralNetwork::initializeWeights()
{
    // Initialize weights or read from file if exists
    string weightsStorageFileName = "./" + this->folderName + "/weights.txt";
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
    for (int i = 0; i < INPUT_NODES; i++)
    {
        this->input[i] = (float)input[i] / 2.00f * 0.99f + 0.01f;
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
    for (int row = 0; row < HIDDEN_NODES; row++)
    {
        for (int column = 0; column < 42; column++)
        {
            weightsStorageFile >> this->wih[row][column];
        }
    }
    for (int row = 0; row < 7; row++)
    {
        for (int column = 0; column < HIDDEN_NODES; column++)
        {
            weightsStorageFile >> this->who[row][column];
        }
    }
}

void NeuralNetwork::initializeWeightsWithRandomNumbers()
{
    cout << "Initializing weights with random numbers..." << std::endl;
    for (int row = 0; row < HIDDEN_NODES; row++)
    {
        for (int column = 0; column < 42; column++)
        {
            this->wih[row][column] = ((float)rand()) / RAND_MAX - 0.5f;
        }
    }
    for (int row = 0; row < 7; row++)
    {
        for (int column = 0; column < HIDDEN_NODES; column++)
        {
            this->who[row][column] = ((float)rand()) / RAND_MAX - 0.5f;
        }
    }
}

void NeuralNetwork::loadNextTrainingLine(ifstream &trainStorageFile)
{
    for (int i = 0; i < 7; i++)
    {
        trainStorageFile >> this->target[i];
    }
    char separarator;
    trainStorageFile >> separarator;
    for (int i = 0; i < INPUT_NODES; i++)
    {
        trainStorageFile >> this->input[i];
    }
}

void NeuralNetwork::printWeightsToFile()
{
    cout << "Writing weights to file..." << std::endl;
    ofstream storageFile;
    string filename = "./" + this->folderName + "/weights.txt";
    storageFile.open(filename);
    if (storageFile)
    {
        for (int row = 0; row < HIDDEN_NODES; row++)
        {
            for (int column = 0; column < 42; column++)
            {
                storageFile << this->wih[row][column] << " ";
            }
            storageFile << std::endl;
        }
        storageFile << std::endl;
        for (int row = 0; row < 7; row++)
        {
            for (int column = 0; column < HIDDEN_NODES; column++)
            {
                storageFile << this->who[row][column] << " ";
            }
            storageFile << std::endl;
        }
        storageFile.close();
    }
    else
        cout << "ERROR: Unable to write weights to file" << std::endl;
}

std::array<float, 7> NeuralNetwork::quest(std::array<int, INPUT_NODES> input)
{
    for (int i = 0; i < INPUT_NODES; i++)
    {
        this->input[i] = (float)input[i] / 2.00f * 0.99f + 0.01f;
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
