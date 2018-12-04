#include "Player.h"
#include "PlayingField.h"
using namespace std;

int Player::lastName = 0;
Player::Player() {
    lastName=lastName +1;
    name = lastName;
}

void Player::printStorageToFile() {
    ofstream storageFile;
    storageFile.open("../storage.txt", std::ios::app);
    if (storageFile)
    {
        storageFile<< "\n \n";
        storage.printToFile(storageFile, name);
        storageFile.close();
    }
    else cout << "Unable to open file";
}
