//
// Created by Britta on 03.12.2018.
//

#ifndef INC_4GEWINNT_MOVE_H
#define INC_4GEWINNT_MOVE_H

#include <array>

class Move
{
  public:
    std::array<std::array<int, 7>, 6> field;
    int targetColumn;
};

#endif //INC_4GEWINNT_MOVE_H
