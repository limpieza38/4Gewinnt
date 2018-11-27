//
// Created by Britta on 14.11.2018.
//

#include <iostream>
#include "PlayingField.h"

/*
* erst die Zeile, dann die Spalte von oben nach unten.
*/

void PlayingField::switchPlayer()
{
    if (currentPlayer == 'a')
    {
        currentPlayer = 'b';
    }
    else
    {
        currentPlayer = 'a';
    }
}

bool PlayingField::proofWinner(int row, int column)
{
    return false;
}

void PlayingField::print()
{
    int i;
    int j;
    for (i = 0; i < this->rows; i++)
    {
        for (j = 0; j < this->columns; j++)
        {
            std::cout << this->field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void PlayingField::setStone(int column)
{
    int i = rows - 1;
    while (i >= 0)
    {
        if (this->field[i][column] == '0')
        {
            this->field[i][column] = this->currentPlayer;
            break;
        }
        i--;
    }
    if (i < 0)
    {
        std::cout << "Column " << column << " is already full!";
        return;
    }
    if (proofWinner(i, column))
    {
        std::cout << "Player " << currentPlayer << " wins!";
        std::cout << std::endl;
    }
    switchPlayer();
};
