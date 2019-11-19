cmake_minimum_required(VERSION 3.15)
project(nagyhazi C)

set(CMAKE_C_STANDARD 99)

add_executable(nagyhazi main.c econio/econio.c econio/econio.h debugmalloc/debugmalloc.h debugmalloc/debugmalloc-impl.h records/records.c records/records.h database/database.c database/database.h menus/menus.c menus/menus.h definitions.h lists/lists.c lists/lists.h utils/utils.c utils/utils.h)