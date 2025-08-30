CC=g++
INDIRS=-Iinclude
FLAGS=-Wall -Wextra -g $(INDIRS)

SRC_DIR=src

SFILES=$(wildcard $(SRC_DIR)/*.cpp )
OBJECTS=$(patsubst %.cpp,%.o,$(SFILES))

BINARY=exec

all: $(BINARY)

$(BINARY): $(OBJECTS)  
	@echo compile $^ from $@ 
	$(CC) -o $@ $^

%.o:%.cpp
	@echo compile $< into $@ 
	$(CC) $(FLAGS) -c -o $@ $<


clean:
	rm -rf $(BINARY) $(OBJECTS)