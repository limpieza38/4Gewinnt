#include "NNPlayer.h"

int NNPlayer::play(PlayingField *_playingField)
{
    std::array<int, 42> input = _playingField->toOneDimensionalArray();
    this->lastOutputs = this->neuralNetwork->questArray(input);

    this->lastMax = 0;
    int column = 0;
    for (int i = 0; i < OUTPUT_NODES; i++)
    {
        if (this->lastOutputs[i] > this->lastMax)
        {
            column = i;
            this->lastMax = this->lastOutputs[i];
        }
    }
    return column;
}

int NNPlayer::chooseOtherColumn()
{
    int column = 0;
    int newMax = 0;
    for (int i = 0; i < OUTPUT_NODES; i++)
    {
        if (this->lastOutputs[i] < this->lastMax && this->lastOutputs[i] > newMax)
        {
            column = i;
            newMax = this->lastOutputs[i];
        }
    }
    this->lastMax = newMax;
    return column;
}

void NNPlayer::train()
{
    this->neuralNetwork->train();
}

void NNPlayer::printStorageToFile()
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

void NNPlayer::saveMove(std::array<std::array<int, 7>, 6> field, int column)
{
    Move move;
    move.field = field;
    std::array<int, 7> targetColumns;
    for (int i = 0; i < 7; i++)
    {
        if (i == column)
        {
            targetColumns[i] = 0;
        }
        else
        {
            targetColumns[i] = 1;
        }
    }
    move.targetColumns = targetColumns;
    this->storage.addMove(move);
}
