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
    char currentPlayer = 'a';
    char field[6][7] = {
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0'}};
    void switchPlayer();
    bool proofWinner(int row, int column);

  public:
    PlayingField(){};
    void print();
    void setStone(int column);
};
#endif //INC_4GEWINNT_PLAYINGFIELD_H
