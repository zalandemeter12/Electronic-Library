sudo apt-get install build-essential

gcc main.c econio/econio.c econio/econio.h debugmalloc/debugmalloc.h debugmalloc/debugmalloc-impl.h records/records.c records/records.h database/database.c database/database.h menus/menus.c menus/menus.h definitions.h lists/lists.c lists/lists.h utils/utils.c utils/utils.h -o ElectronicLibrary

./ElectronicLibrary

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./ElectronicLibrary