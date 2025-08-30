SRC_DIR=src
BUILD_DIR=build
HEADERS_DIR=include

CC=g++
INDIRS=-I$(HEADERS_DIR)
FLAGS=-Wall -Wextra -g $(INDIRS)

SOURCES=$(wildcard $(SRC_DIR)/*.cpp )
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
HEADERS=$(wildcard $(HEADERS_DIR)/*.h )

BINARY=exec

all: $(BINARY)

$(BINARY): $(OBJECTS) 
	@echo compile $^ into $@ 
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)| $(BUILD_DIR)
	@echo compile $< into $@ 
	$(CC) $(FLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $@


clean:
	rm -rf $(BINARY) $(OBJECTS)