cmake_minimum_required(VERSION 3.15)
project(nagyhazi C)

set(CMAKE_C_STANDARD 99)

add_executable(nagyhazi main.c records/records.c records/records.h database/database.c database/database.h menus/menus.c menus/menus.h definitions.h)