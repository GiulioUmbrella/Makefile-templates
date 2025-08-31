SRC_DIR=src
BUILD_DIR=build
HEADERS_DIR=include

CC=g++
FLAGS=-Wall -Wextra -g -I$(HEADERS_DIR) -MMD -MP

SOURCES=$(wildcard $(SRC_DIR)/*.cpp )
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEPS   =$(OBJECTS:.o=.d )

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

-include $(DEPS)


clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPS)