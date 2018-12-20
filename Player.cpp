#include "Player.h"
#include "PlayingField.h"

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
        cout << "Unable to open file";
}
