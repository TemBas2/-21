all: Quest_1

Quest_1: dmanager_module.o
	gcc -Wall -Wextra -Werror dmanager_module.o -o ../build/Quest_1 -lm

dmanager_module.o: dmanager_module.c
	gcc -Wall -Wextra -Werror -c -o dmanager_module.o dmanager_module.c
clean:
	rm -f *.o Quest_1

rebuild: clean all
