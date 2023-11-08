cmake_minimum_required(VERSION 3.25)
project(ADT_Studenti C)

set(CMAKE_C_STANDARD 11)

add_executable(ADT_Studenti main.c Studente/Studente.h Studente/Studente.c)
