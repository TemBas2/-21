all: cipher

cipher: cipher.o
	gcc -Wall -Wextra -Werror cipher.o -o ../build/cipher -lm

cipher.o: cipher.c
	gcc -Wall -Wextra -Werror -c -o cipher.o cipher.c

clean:
	rm -f *.o

rebuild: clean all
