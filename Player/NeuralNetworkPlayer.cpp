//
// Created by Britta on 28.11.2018.
//
#include "Player.h"
#include "NeuralNetworkPlayer.h"
#include "../PlayingField.h"

int NeuralNetworkPlayer::play(PlayingField *_playingField) {
    std::array<float, INPUT_NODES> input = transformFieldToInput(_playingField);
    int column = neuralNetwork.quest(input);
    return column;
}

std::array<float, INPUT_NODES> NeuralNetworkPlayer::transformFieldToInput(PlayingField *playingField) {
        std::array<float, INPUT_NODES> input;
        int inId = 0;
        for (int row = 0; row < ROWS; row++) {
            for (int column = 0; column < COLUMNS; column++) {
                input[inId] = neuralNetwork.transformInput(playingField->field[row][column]);
                inId++;
            }
        }
        return input;
}
