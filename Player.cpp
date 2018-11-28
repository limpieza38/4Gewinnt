#include "Player.h"
#include "PlayingField.h"


char Player::lastName = '@';

Player::Player() {
    lastName++;
    name = lastName;
}
