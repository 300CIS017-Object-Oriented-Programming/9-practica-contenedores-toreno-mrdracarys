cmake_minimum_required(VERSION 3.19)
project(BattleArena)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

add_executable(BattleArena
        main.cpp
        src/Torneo.cpp
        src/Torneo.h
        src/Videojuego.cpp
        src/Videojuego.h
        src/Jugador.cpp
        src/Jugador.h
)


set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
