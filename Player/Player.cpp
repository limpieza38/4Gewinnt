#include "Player.h"
#include "../PlayingField.h"

using namespace std;

Player::Player(int name)
{
    this->name = name;
}

void Player::printStorageToFile()
{
    ofstream storageFile;
    string filename = "./player" + to_string(this->name) + "/train_data.txt";
    storageFile.open(filename, std::ios::app);
    if (storageFile)
    {
        storageFile << "\n\n";
        storage.printToFile(storageFile);
        storageFile.close();
    }
    else
        cout << "ERROR: Unable to open file to print the storage";
}

void Player::saveMove(std::array<std::array<int, 7>, 6> field, int column)
{
    Move move;
    move.field = field;
    std::array<int, 7> targetColumns;
    for (int i = 0; i < 7; i++)
    {
        if (i == column)
        {
            targetColumns[i] = 1;
        }
        else
        {
            targetColumns[i] = 0;
        }
    }
    move.targetColumns = targetColumns;
    this->storage.addMove(move);
}
