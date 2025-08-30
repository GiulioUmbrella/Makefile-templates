# Makefile templates

A collection of Makefiles for managing small to medium-sized projects. Each version builds on the previous one, extending its functionality.

# 01-simple

The simple example takes a list of source files specified in the variable SFILES and a corresponding list of object files in OBJECT. The binary exe is the target to be built. When this target is reached, the Makefile compiles each .cpp file into its corresponding .o file, without linking.

Next, the compiler is invoked to combine all the right-hand-side elements (specified by the special character $^) and create the object $@.


 