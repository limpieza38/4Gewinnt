#include <iostream>
#include "PlayingField.cpp"
#include "Player.cpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    PlayingField playingField;
    RandomPlayer randomPlayer;
    int col = randomPlayer.play(playingField.getField());
    playingField.setStone(col);

    playingField.printField();
    return 0;
}

