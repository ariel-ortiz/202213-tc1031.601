# Mi primer Makefile

CC=g++

main: main.o factorial.o
	$(CC) -o main main.o factorial.o

main.o: main.cpp factorial.h
	$(CC) -c main.cpp

factorial.o: factorial.cpp factorial.h
	$(CC) -c factorial.cpp
	
clean:
	rm -f main main.o factorial.o
