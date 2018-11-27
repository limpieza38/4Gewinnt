//
// Created by Britta on 14.11.2018.
//

#ifndef INC_4GEWINNT_PLAYINGFIELD_H
#define INC_4GEWINNT_PLAYINGFIELD_H

class PlayingField
{
private:
  const int rows = 6;
  const int columns = 7;
  int stones = 0;
  int maxStones = 42;
  int lastRow = -1;
  int lastColumn = -1;
  char field[6][7] = {
      {'0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0'}};

public:
  char currentPlayer = 'a';
  PlayingField(){};
  void print();
  bool setStone(int column);
  void switchPlayer();
  bool proofWinner();
  bool isFull();
};
#endif //INC_4GEWINNT_PLAYINGFIELD_H
