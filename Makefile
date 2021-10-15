# CIUREA Robert-Mihai - 313CB

build:
	gcc main.c list.c H.c -o tema1 -Wall -g -std=c99

run:
	./tema1 4 ./input/Test5.in hash1.out

valgrind:
	valgrind --leak-check=full ./tema1 4 ./input/Test5.in hash1.out

clean:
	rm -rf tema1