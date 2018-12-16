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
    string filename = "./storage/" + to_string(name) + ".txt";
    storageFile.open(filename, std::ios::app);
    if (storageFile)
    {
        storageFile << "\n\n";
        storage.printToFile(storageFile, name);
        storageFile.close();
    }
    else
        cout << "Unable to open file";
}
