CC=g++
INDIRS=-I.
FLAGS=-Wall -Wextra -g $(INDIRS)

SFILES=main.cpp foo.cpp
OBJECTS=main.o foo.o

BINARY=exec

all: $(BINARY)

$(BINARY): $(OBJECTS)  
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $() -c -o $@ $^ $(FLAGS)


clean:
	rm -rf $(BINARY) $(OBJECTS)