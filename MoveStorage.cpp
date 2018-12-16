//
// Created by Britta on 03.12.2018.
//

#include <iostream>
#include "MoveStorage.h"

void MoveStorage::addMove(Move move)
{
    if (countMoves < 21)
    {
        moves[countMoves] = move;
        countMoves++;
    }
}

void MoveStorage::printToFile(ofstream &file, int name)
{
    for (int i = 0; i < countMoves; i++)
    {
        file << moves[i].targetColumn << " ";
        for (int row = 0; row < 6; row++)
        {
            for (int col = 0; col < 7; col++)
            {
                file << moves[i].field[row][col] << " ";
            }
        }
        file << std::endl;
    }
    file << std::endl;
}
