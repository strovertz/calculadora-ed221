cmake_minimum_required(VERSION 3.22)
project(untitled2)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(teste
        pilha.c
        pilha.h
        interface.c
        interface.h
        main.c)
