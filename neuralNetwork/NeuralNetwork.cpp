#include <iostream>
#include "NeuralNetwork.h"

using namespace std;

void NeuralNetwork::train()
{
    std::cout << "TRAINING" << std::endl;
}

int NeuralNetwork::quest(PlayingField *playingField)
{
}

void NeuralNetwork::printWeightsToFile()
{
    ofstream storageFile;
    // string filename = ".weightStorage.txt";
    // storageFile.open(filename, std::ios::app);
    // if (storageFile)
    // {
    //     storageFile << "\n\n";
    //     storage.printToFile(storageFile, "test");
    //     storageFile.close();
    // }
    // else
    //     cout << "Unable to open file";
}
