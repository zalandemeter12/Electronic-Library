cmake_minimum_required(VERSION 3.15)
project(nagyhazi C)

set(CMAKE_C_STANDARD 99)

add_executable(nagyhazi main.c records.c records.h database.c database.h menus.c menus.h definitions.h)