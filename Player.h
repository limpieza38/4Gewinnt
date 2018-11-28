//
// Created by Britta on 28.11.2018.
//

#ifndef INC_4GEWINNT_PLAYER_H
#define INC_4GEWINNT_PLAYER_H


class PlayingField;

class Player {
private:
    static char lastName;
public:
    char name;
    Player();
    virtual int play(PlayingField* _playingField)=0;
};


#endif //INC_4GEWINNT_PLAYER_H
