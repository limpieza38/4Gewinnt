//
// Created by Britta on 03.12.2018.
//

#ifndef INC_4GEWINNT_MOVESTORAGE_H
#define INC_4GEWINNT_MOVESTORAGE_H
#include <iostream>
#include <fstream>
using namespace std;

#include "Move.h"

class MoveStorage {
private:
        int countMoves = 0;
        Move moves[21];
public:
        void printToFile(ofstream &file);
        void addMove(Move move);
};


#endif //INC_4GEWINNT_MOVESTORAGE_H
