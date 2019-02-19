# Debug Tools

Designed by Junyi Yang(yangrebelice@gmail.com)

## Introduction

In this lab, we'll know a debug tool, `Valgrind`. We'll introduce only one Valgrind tool, `Memcheck`, which can be used to find memory bugs.

See [valgrind.org](www.valgrind.org) for details. 

## **TODO**

You will get an overview of `memcheck` by completing the following tasks.
If you have problems in the process of completing, you can use any way to solve them.

1. Check if uninitialized memory is being used.
	```
	# Entry the directory
	cd Uninitialized

	# Compile source code
	# See the Makefile for details
	make

	# Using valgrind memcheck
	valgrind ./Uninitialized
	```
	- Use the above command to see output.
	- You also need to see `Uninitialized.c` for more information.
	- Understand the output.

2. Check if write or read out of bound.
	```
	# Entry the directory
	cd OutOfBound

	# Compile source code
	# See the Makefile for details
	make

	valgrind ./OutOfBound
	```
	- Use the above command to see output.
	- You also need to see `OutOfBound.c` for more information.
	- Understand the output.

3. Check if overlap.
	```
	# Entry the directory
	cd Overlap

	# Compile source code
	# See the Makefile for details
	make

	valgrind ./Overlap
	```
	- Use the above command to see output.
	- You also need to see `Overlap.c` for more information.
	- Understand the output.

4. Check dynamic memory management.
	```
	# Entry the directory
	cd DynamicMemory

	# Compile source code
	# See the Makefile for details
	make

	valgrind ./DynamicMemory
	```
	- Use the above command to see output.
	- You also need to see `DynamicMemory.c` for more information.
	- Understand the output.

5. Check memory leak.
	```
	# Entry the directory
	cd MemoryLeak

	# Compile source code
	# See the Makefile for details
	make

	# Carefully!
	valgrind --leak-check=full ./MemoryLeak
	```
	- Use the above command to see output.
	- You also need to see `MemoryLeak.c` for more information.
	- Understand the output.
	- Distinguish between `definitely lost` and `indirectly lost`.

## References
- UNIX system manuals
- W. Richard Stevens, Stephen A. Rago. Advanced Programming in the Unix Environment, Third Edition. Person Education, Inc.. 2013
- [Operating System: Three Easy Pieces](http://pages.cs.wisc.edu/~remzi/OSTEP/)
