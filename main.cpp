#include <iostream>
#include "PlayingField.h"

int main()
{
    std::cout << "4 Gewinnt" << std::endl;
    PlayingField playingField;
    playingField.print();
    while (true)
    {
        std::cout << "Choose column to play: ";
        int col;
        std::cin >> col;
        playingField.setStone(col);
        playingField.print();
    }
    return 0;
}
