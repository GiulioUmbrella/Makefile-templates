CC=g++
INDIRS=-I.
FLAGS=-Wall -Wextra -g $(INDIRS)

BINARY=exec

all: $(BINARY)

$(BINARY): main.cpp foo.cpp
	$(CC) -o $(BINARY) main.cpp foo.cpp $(FLAGS)

clean:
	rm $(BINARY) 