#include <iostream>
#include "PlayingField.h"

int main()
{
    std::cout << "4 Gewinnt" << std::endl;
    PlayingField playingField;
    playingField.print();
    while (true)
    {
        int col;
        std::cout << "Player " << playingField.currentPlayer << ", choose column to play: ";
        std::cin >> col;
        bool ok = playingField.setStone(col - 1);
        if (ok)
        {
            playingField.print();
            if (playingField.proofWinner())
            {
                std::cout << "Player " << playingField.currentPlayer << " wins!" << std::endl;
                break;
            }
            if (playingField.isFull())
            {
                std::cout << "Remis!" << std::endl;
                break;
            }
            playingField.switchPlayer();
        }
        else
        {
            std::cout << "Column " << col << " is already full!" << std::endl;
        }
    }
    return 0;
}
