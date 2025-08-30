CC=g++
INDIRS=-Iinclude
FLAGS=-Wall -Wextra -g $(INDIRS)

SRC_DIR=src
BUILD_DIR=build

SFILES=$(wildcard $(SRC_DIR)/*.cpp )
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SFILES))

BINARY=exec

all: $(BINARY)

$(BINARY): $(OBJECTS)  
	@echo compile $^ into $@ 
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo compile $< into $@ 
	$(CC) $(FLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $@


clean:
	rm -rf $(BINARY) $(OBJECTS)