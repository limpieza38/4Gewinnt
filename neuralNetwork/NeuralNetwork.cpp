#include <iostream>
#include <fstream>
#include "NeuralNetwork.h"
#include "Helper.h"

using namespace std;

void NeuralNetwork::train()
{
    cout << "TRAINING:" << std::endl;

    // Initialize weights or read from file if exists
    string weightsStorageFileName = "./player" + to_string(this->player->name) + "/weights.txt";
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

    ifstream trainStorageFile;
    string filename = "./player" + to_string(this->player->name) + "/train_data.txt";
    trainStorageFile.open(filename);
    if (trainStorageFile)
    {
        while (!trainStorageFile.eof())
        {
            cout << "Training with next training data line..." << std::endl;
            this->loadNextTrainingLine(trainStorageFile);
            // TODO: Train
        }
        trainStorageFile.close();
    }
    else
        cout << "ERROR: Unable to open training data file" << std::endl;

    this->printWeightsToFile();
}

void NeuralNetwork::loadWeightsFromFile(ifstream &weightsStorageFile)
{
    cout << "Reading weights from file..." << std::endl;
    for (int row = 0; row < HIDDEN_NODES; row++)
    {
        for (int column = 0; column < 42; column++)
        {
            weightsStorageFile >> this->weights1[row][column];
        }
    }
    for (int row = 0; row < 7; row++)
    {
        for (int column = 0; column < HIDDEN_NODES; column++)
        {
            weightsStorageFile >> this->weights2[row][column];
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
            this->weights1[row][column] = ((float)rand()) / RAND_MAX - 0.5;
        }
    }
    for (int row = 0; row < 7; row++)
    {
        for (int column = 0; column < HIDDEN_NODES; column++)
        {
            this->weights2[row][column] = ((float)rand()) / RAND_MAX - 0.5;
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
    for (int i = 0; i < 42; i++)
    {
        trainStorageFile >> this->input[i];
    }
}

void NeuralNetwork::printWeightsToFile()
{
    cout << "Writing weights to file..." << std::endl;
    ofstream storageFile;
    string filename = "./player" + to_string(this->player->name) + "/weights.txt";
    storageFile.open(filename);
    if (storageFile)
    {
        for (int row = 0; row < HIDDEN_NODES; row++)
        {
            for (int column = 0; column < 42; column++)
            {
                storageFile << this->weights1[row][column] << " ";
            }
            storageFile << std::endl;
        }
        storageFile << std::endl;
        for (int row = 0; row < 7; row++)
        {
            for (int column = 0; column < HIDDEN_NODES; column++)
            {
                storageFile << this->weights2[row][column] << " ";
            }
            storageFile << std::endl;
        }
        storageFile.close();
    }
    else
        cout << "ERROR: Unable to write weights to file" << std::endl;
}

int NeuralNetwork::quest(PlayingField *playingField)
{
}
