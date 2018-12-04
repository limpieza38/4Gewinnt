cmake_minimum_required(VERSION 3.9)
project(4Gewinnt)

set(CMAKE_CXX_STANDARD 11)

add_executable(4Gewinnt main.cpp PlayingField.cpp PlayingField.h Player.h Player.h Player.cpp RandomPlayer.cpp RandomPlayer.h CmdInputPlayer.cpp CmdInputPlayer.h MoveStorage.cpp MoveStorage.h Move.cpp Move.h GameMachine.cpp GameMachine.h)