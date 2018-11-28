#include <iostream>
#include "Player.h"
#include "PlayingField.h"
#include "RandomPlayer.h"

int main()
{
    srand (time(0));
    std::cout << "4 Gewinnt" << std::endl;
    RandomPlayer playerA;
    RandomPlayer playerB;
    PlayingField playingField(&playerA, &playerB);
    playingField.print();
    while (true)
    {
        int col = playingField.currentPlayer->play(&playingField);
        bool ok = playingField.setStone(col);
        if (ok)
        {
            playingField.print();
            if (playingField.proofWinner())
            {
                std::cout << "Player " << playingField.currentPlayer->name << " wins!" << std::endl;
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
