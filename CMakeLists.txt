cmake_minimum_required(VERSION 3.9)
project(4Gewinnt)

set(CMAKE_CXX_STANDARD 11)


add_executable(4Gewinnt main.cpp PlayingField.cpp PlayingField.h  Player/NeuralNetworkPlayer.h Player/NeuralNetworkPlayer.cpp Player/Player.h Player/Player.cpp Player/RandomPlayer.cpp Player/RandomPlayer.h Player/CmdInputPlayer.h Player/CmdInputPlayer.cpp  MoveStorage.cpp MoveStorage.h Move.cpp Move.h GameMachine.cpp GameMachine.h neuralNetwork/NeuralNetwork.cpp neuralNetwork/NeuralNetwork.h neuralNetwork/Helper.cpp neuralNetwork/Helper.h)