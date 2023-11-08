cmake_minimum_required(VERSION 3.25)
project(Gestione_Corso_Universitario C)

set(CMAKE_C_STANDARD 11)

add_executable(Gestione_Corso_Universitario main.c "Corso_Universitario/Corso_Universitario.h" "Corso_Universitario/Corso_Universitario.c" Gestione_File/File.h Gestione_File/File.c)
