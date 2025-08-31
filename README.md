# Makefile templates

A collection of Makefiles for managing small to medium-sized projects. Each version builds on the previous one, extending its functionality.

## 00-intro

The intro shows the basic structure of a Makefile

First, we define some variables.

```bash
CC=g++                            # compiler                          
INDIRS=-I.                        # directory with headers
FLAGS=-Wall -Wextra -g $(INDIRS)  # compilation flag

BINARY=exec                       # name of the executable
```

Next we introduce a *rule*. When invoked, the Makefile looks for the first rule, which by convention is all. This rule depends on the file named `BINARY`. Running make will therefore hits the all rule. As the rule has a dependency on `BINARY`, make will checks if other rules depend on them in a chain reaction mechanism. 

```bash
all: $(BINARY)
```

The following rule executes the compilation. The `BINARY` variable depends on two files: main.o and foo.o. When the execution reaches this line, make checks for other rules targeting them.


```bash
$(BINARY): main.o foo.o
	$(CC) -o $(BINARY) main.o foo.o $(FLAGS)
```

Indeed, there are two specific rules. If main.cpp or foo.cpp are modifided, make recompiles the file which are in turn used for creating the `BINARY` executable. 

```bash
main.o: main.cpp
	$(CC) -c -o main.o main.cpp $(FLAGS)

foo.o: foo.cpp
	$(CC) -c -o foo.o foo.cpp $(FLAGS)
```

In addition, we can specify other rules. To invoke this we have to type the command `make clean` to skip the first `all` rule. The convention is to name clean the set of operations for cleaning the files. 

```bash
clean:
	rm $(BINARY) 
```


## 01-simple

The simple example takes a list of source files specified in the variable SFILES and a corresponding list of object files in OBJECT. The binary exe is the target to be built. When this target is reached, the Makefile compiles each .cpp file into its corresponding .o file, without linking.

Next, the compiler is invoked to combine all the right-hand-side elements specified by the special character `$^` and create the object `$@`.


## 02-src-loop

The src-loop introduces some improvements: the code is now organized into directories. The SFILES list is generated using the wildcard operator, which collects all .cpp files in the SRC_DIR directory. The OBJECTS list is then derived by substituting the .cpp file extension with .o. The INDIRS flag now specifies the include directory. The rest of the file remains unchanged.

## 03-build-directory

To store the object files, the build-directory introduces a dedicated build directory. The SFILE remains the same, bu the OBJECT list is modified to palce the .o files inside BUILD_DIR. Because the .o files and .ccp files are now in different directories, the single-file compilation loop must be updated accordingly. 

An additional dependency is added by appending | `$(BUILD_DIR)` to the loop. This ensures that make first checks whether the build directory exists and creates it if necessary, before compiling the individual source files.

## 04-header-simple

The previous example has a major limitation: it does not account for modifications in the header files. The include directory points to them, but the rules do not check for changes. A simple trick to track modifications is to add a list of headers and then set this list as prerequisites in the rule:

```bash
HEADERS=$(wildcard $(HEADERS_DIR)/*.h )

# ....

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)| $(BUILD_DIR)
	@echo compile $< into $@ 
	$(CC) $(FLAGS) -c -o $@ $<
```

The HEADERS variable is now a dependency of each object file compilation. However, this technique suffers from a major drawback: a single header modification will trigger the recompilation of all the files. When any header changes, make considers every object file target out of date, since HEADERS is just a list of all headers and does not take into account whether a specific source file actually includes the modified header. 