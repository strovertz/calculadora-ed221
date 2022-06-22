cmake_minimum_required(VERSION 3.22)
project(calculadora_ed221_main C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(calculadora_ed221_main
        calculadora.c
        calculadora.h
        data.h
        interface.c
        interface.h
        main.c
        pilha.c
        pilha.h)
