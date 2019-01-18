cmake_minimum_required(VERSION 3.11.2)
project(cpp_solitaire)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_solitaire main.cpp Solitaire.cpp Solitaire_AI.cpp Tableau.cpp Foundation.cpp Highscore.cpp Stock.cpp Card.cpp Stack.cpp Pile.cpp Reserve.cpp Waste.cpp)
