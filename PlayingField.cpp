//
// Created by Britta on 14.11.2018.
//


#include <iostream>

#define ROWS 6
#define COLUMNS 7


class PlayingField {
    /*
     * erst die Zeile, dann die Splate vo oben nach unten.
     */
    int field[ROWS][COLUMNS] = {
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0},

    };
    int currentPlayer = 1;
    int numberOfMoves = 0;

    void swtichPlayer() {
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }

    bool proofWinner(int row, int col, int player) {
        int counter, i;
        if (numberOfMoves < 7) {
            return false;
        }
        /* Reihe */
        counter = 0;
        for (i = 0; i < COLUMNS; i++) {
            if (field[row][i] == player) {
                counter++;
                if (counter == 4) {
                    return true;
                }
            } else {
                counter = 0;
            }
        }
        /* Spalte */
        counter = 0;
        for (i = 0; i < ROWS; i++) {
            if (field[i][col] == player) {
                counter++;
                if (counter == 4) {
                    return true;
                }
            } else {
                counter = 0;
            }
        }
        /*Diagonal */


    }


public:
    PlayingField(){
    }

    int *getField() {
        return *field;
    }

    int setStone(int column) {
        int i = ROWS - 1;
        while (i >= 0) {
            if (field[i][column] == 0) {
                field[i][column] = currentPlayer;
                numberOfMoves = numberOfMoves + 1;

                break;
            }
            i--;
        }
        if (i < 0) {
            return i;
        }
        if(proofWinner(i, column, currentPlayer)){
            std::cout << "Player " << currentPlayer << " wins!";
            std::cout << std::endl;;
        }
        swtichPlayer();
        return 0;
    };

    void printField() {
        int i ;
        int j;
        for (i = 0;  i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                std::cout << field[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
};