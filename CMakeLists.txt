cmake_minimum_required(VERSION 3.26)
project(BattleshipFinal)

set(CMAKE_CXX_STANDARD 17)

add_executable(BattleshipFinal main.cpp
        includes/piece.h
        includes/piece.cpp
        includes/board.cpp
        includes/menu.cpp
        includes/menu.h
        includes/highscores.cpp)
