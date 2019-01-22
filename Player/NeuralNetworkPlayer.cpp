//
// Created by Britta on 28.11.2018.
//

#include "NeuralNetworkPlayer.h"

int NeuralNetworkPlayer::play(PlayingField *_playingField)
{
    std::array<int, INPUT_NODES> input = _playingField->toOneDimensionalArray();
    std::array<float, OUTPUT_NODES> output = neuralNetwork.questArray(input);

    while (true)
    {
        int col = 0;
        float max = 0;
        for (int i = 0; i < OUTPUT_NODES; i++)
        {
            if (output[i] > max)
            {
                col = i;
                max = output[i];
            }
        }
        bool ok = _playingField->tryStone(col, this->name);
        if (ok)
        {
            this->saveMove(_playingField->copyField(), col);
            _playingField->setStone(col, this->name);
            return col;
        }
        else
        {
            output[col] = -1; // Beim nächsten Durchlauf wird diese Spalte nicht mehr genommen
        }
    }
    return 0;
}

void NeuralNetworkPlayer::train()
{
    this->neuralNetwork.train();
}

void NeuralNetworkPlayer::saveMove(std::array<std::array<int, 7>, 6> field, int column)
{
    Move move;
    move.field = field;
    std::array<int, 7> targetColumns;
    for (int i = 0; i < 7; i++)
    {
        targetColumns[i] = 1;
    }
    targetColumns[column] = 0;
    move.targetColumns = targetColumns;
    this->storage.addMove(move);
}

void NeuralNetworkPlayer::printStorageToFile()
{
    ofstream storageFile;
    string filename = "./player" + to_string(this->name) + "/train_data.txt";
    storageFile.open(filename);
    if (storageFile)
    {
        storage.printToFile(storageFile);
        storageFile.close();
    }
    else
        cout << "ERROR: Unable to open file to print the storage";
}
