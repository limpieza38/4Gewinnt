//
// Created by Britta on 14.11.2018.
//

#include <iostream>
#include "PlayingField.h"

bool PlayingField::proofWinner()
{
    int stones = 1;
    int r = lastRow;
    int c = lastColumn;
    int lastColor = field[lastRow][lastColumn];

    // Row:
    // Nach links:
    while (--c >= 0)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    c = lastColumn;
    // Nach rechts:
    while (++c < columns)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    if (stones >= 4)
    {
        return true;
    }

    // Column:
    stones = 1;
    r = lastRow;
    c = lastColumn;
    // Nach oben:
    while (--r >= 0)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    r = lastRow;
    // Nach unten:
    while (++r < rows)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    if (stones >= 4)
    {
        return true;
    }

    // Diagonal von oben links nach unten rechts:
    stones = 1;
    r = lastRow;
    c = lastColumn;
    // Nach oben links:
    while (--r >= 0 && --c >= 0)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    r = lastRow;
    c = lastColumn;
    // Nach unten rechts:
    while (++r < rows && ++c < columns)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    if (stones >= 4)
    {
        return true;
    }

    // Diagonal von unten links nach oben rechts:
    stones = 1;
    r = lastRow;
    c = lastColumn;
    // Nach unten links:
    while (++r < rows && --c >= 0)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    r = lastRow;
    c = lastColumn;
    // Nach oben rechts:
    while (--r >= 0 && ++c < columns)
    {
        if (field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    if (stones > 3)
    {
        return true;
    }
    return false;
}

bool PlayingField::isFull()
{
    return stones >= maxStones;
}

void PlayingField::print()
{
    std::cout << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool PlayingField::setStone(int column, int color)
{
    int row = rows - 1;
    while (row >= 0)
    {
        if (field[row][column] == 0)
        {
            field[row][column] = color;
            break;
        }
        row--;
    }
    if (row < 0)
        return false;
    stones++;
    lastRow = row;
    lastColumn = column;
    return true;
};

std::array<std::array<int, 7>, 6> PlayingField::copyField()
{
    std::array<std::array<int, 7>, 6> target;
    std::copy(std::begin(field), std::end(field), std::begin(target));
    return target;
}

std::array<int, 42> PlayingField::toOneDimensionalArray()
{
    std::array<int, 42> oneDimArray;
    for (int i = 0; i < 42; i++)
    {
        oneDimArray[i] = this->field[i / 7][i % 7];
    }
    return oneDimArray;
}
