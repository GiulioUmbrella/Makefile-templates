# Makefile templates

A collection of Makefiles for managing small to medium-sized projects. Each version builds on the previous one, extending its functionality.

# 01-simple

The simple example takes a list of source files specified in the variable SFILES and a corresponding list of object files in OBJECT. The binary exe is the target to be built. When this target is reached, the Makefile compiles each .cpp file into its corresponding .o file, without linking.

Next, the compiler is invoked to combine all the right-hand-side elements (specified by the special character $^) and create the object $@.


# 02-src-loop

The src loop introduces some improvements: the code is now organized into directories. The SFILES list is generated using the wildcard operator, which collects all .cpp files in the SRC_DIR directory. The OBJECTS list is then derived by substituting the .cpp file extension with .o. The INDIRS flag now specifies the include directory. The rest of the file remains unchanged.

 