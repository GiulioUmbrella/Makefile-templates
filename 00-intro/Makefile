CC=g++
INDIRS=-I.
FLAGS=-Wall -Wextra -g $(INDIRS)

BINARY=exec

all: $(BINARY)

$(BINARY): main.o foo.o
	$(CC) -o $(BINARY) main.o foo.o $(FLAGS)

main.o: main.cpp
	$(CC) -c -o main.o main.cpp $(FLAGS)

foo.o: foo.cpp
	$(CC) -c -o foo.o foo.cpp $(FLAGS)

clean:
	rm $(BINARY) main.o foo.o
