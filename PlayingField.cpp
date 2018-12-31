//
// Created by Britta on 14.11.2018.
//

#include <iostream>
#include <array>
#include "PlayingField.h"

bool PlayingField::proofWinner()
{
    int stones = 1;
    int r = this->lastRow;
    int c = this->lastColumn;
    int lastColor = this->field[lastRow][lastColumn];

    // Row:
    // Nach links:
    while (--c >= 0)
    {
        if (this->field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    c = lastColumn;
    // Nach rechts:
    while (++c < COLUMNS)
    {
        if (this->field[r][c] == lastColor)
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
    r = this->lastRow;
    c = this->lastColumn;
    // Nach oben:
    while (--r >= 0)
    {
        if (this->field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    r = lastRow;
    // Nach unten:
    while (++r < ROWS)
    {
        if (this->field[r][c] == lastColor)
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
    r = this->lastRow;
    c = this->lastColumn;
    // Nach oben links:
    while (--r >= 0 && --c >= 0)
    {
        if (this->field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    r = this->lastRow;
    c = this->lastColumn;
    // Nach unten rechts:
    while (++r < ROWS && ++c < COLUMNS)
    {
        if (this->field[r][c] == lastColor)
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
    r = this->lastRow;
    c = this->lastColumn;
    // Nach unten links:
    while (++r < ROWS && --c >= 0)
    {
        if (this->field[r][c] == lastColor)
            stones++;
        else
            break;
    }
    r = this->lastRow;
    c = this->lastColumn;
    // Nach oben rechts:
    while (--r >= 0 && ++c < COLUMNS)
    {
        if (this->field[r][c] == lastColor)
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
    return this->stones >= this->maxStones;
}

void PlayingField::print()
{
    std::cout << std::endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool PlayingField::setStone(int column, int color)
{
    int row = ROWS - 1;
    while (row >= 0)
    {
        if (this->field[row][column] == 0)
        {
            this->field[row][column] = color;
            this->stones++;
            this->lastRow = row;
            this->lastColumn = column;
            return true;
        }
        row--;
    }
    return false;
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
