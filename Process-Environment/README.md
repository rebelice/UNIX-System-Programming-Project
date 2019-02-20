# Process Environment Lab

Designed by Junyi Yang(yangrebelice@gmail.com)

## Introduction

In this lab, we'll see how a C program is compiled and executed in the UNIX Environment. I'll introduce some basic knowledge about that. And you also need to write some codes and run them. Don't worry, it's far too easy.

## Process Environment

### `main` Function and Command-Line Arguments

As we know, a C program starts execution with `main` function. The prototype for the `main` function is
```
	int main(int argc, char *argv[]);
```
where `argc` is the number of command-line arguments, and `agrv` is an array of pointers to the arguments.

We have provided a simple C program `main-function.c` as an example. 

**TODO**:
1. See that how to use `argc` and `argv`.
	- There are two ways.
2. Compile it as above, use flag `-o main-function`.
3. Run it as `./main-function Fudan University ICS 2019 OS Project`. To see the output.

Now, I think you already know how to use `argc` and `argv`. Please finish the following.

**TODO**:
- You need to code a C program to solve a `a + b Problem` by using `argv`. 
- The only thing you need to pay attention to is that you should run it as `./addition-problem 1 2`.
- For convenience, we can suppose that the input numbers are integers which are in the range of 0 to 9. 
- No restrictions on the name of your program.

### Process Termination

Here we only introduce three ways to terminate a process.

1. Return from `main`
2. Calling `exit`
3. calling `_exit` or `_Exit`

Followings are something you need to know.

1. Returning an integer value from the `main` function is equivalent to calling `exit` with the same value. Thus `exit(0);` is the same as `return 0;` from the `main` function.
2. `exit` performs certain cleanup processing (such as standard I/O cleanup) and then returns to the kernel.
3. `_exit` and `_Exit` return to the kernel immediately.

If you want to know more information, find in the manual or references.

## Use Manual

We'd like you to know how to use manual.
The notation `gcc(1)` is the normal way to reference a particular entry in the UNIX system manuals. It refers to the entry for `gcc` in Section 1. The sections are normally numbered 1 through 8, and all the entries within each section are arranged alphabetically.

- If you have a copy of the manuals for your UNIX system, you can use `man 1 gcc` in the terminal to find in the manual.
- If you don't know the section number, you can use `man gcc`.

## References

- UNIX system manuals
- W. Richard Stevens, Stephen A. Rago. Advanced Programming in the Unix Environment, Third Edition. Person Education, Inc.. 2013
