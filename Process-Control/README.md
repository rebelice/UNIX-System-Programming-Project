# Process Control

Designed by Junyi Yang(yangrebelice@gmail.com)

## Introduction

In this lab, we'll see how to control processes in the UNIX Environment.
The primary coverage includes the creation of new processes, program execution, process termination and interprocess communication.

## Process Identifiers

We'll introduce two functions:

```
#include <unistd.h>

pid_t getpid(void);
	//Returns: process ID of calling process.
pid_t getppid(void);
	//Returns: parent process ID of calling process.
```

`getpid(2)` for more details.

## `fork` Function

An existing process can create a new one by calling the `fork` function.

```
#include <unistd.h>

pid_t fork(void);
	//Returns: 0 in child, process ID of child in parent, -1 on error.
```

`fork(2)` for more details.

## `wait` and `waitpid` Functions

A process calling `wait` or `waitpid` can
- Block, if all of its children are still running
- Return immediately with the termination status of a child, if a child has terminated and is waiting for its termination status to be fetched
- Return immediately with an error, if it dosen't have any child processes

```
#include <sys/wait.h>

pid_t wait(int *statloc);

pid_t waitpid(pid_t pid, int *statloc, int options);
	//Both return: process ID if OK, 0, or -1 on error
```

We don't talk more about `waitpid`. Yon can find more details with `wait(2)`. 

## `exec` Functions

When a process calls one of the exec functions, that process is completely replaced by the new program, and the new program starts executing at its `main` function.

Followings are six variants of `exec`:
- `execl()`
- `execv()`
- `execle()`
- `execve()`
- `execlp()`
- `execvp()`

`exec(3)` for more details.

## Pieps

Pipes are the most commonly used form of interprocess communication(IPC).

A pipe is created by calling the `pipe` function.

```
#include <unistd.h>

int pipe(int fd[2]);
	//Returns: 0 if OK, -1 on error.
```

`fd[0]` and `fd[1]` are two file descriptors where `fd[0]` is open for reading, and `fd[1]` is open for writing. The output of `fd[1]` is the input for `fd[0]`.

`pipe(2)` for more details.

## **TODO**

1. Read the program, `fork-and-variable.c`, and change it. Answer the following questions.
	1. Whithout changing, what value is the variable in the child process, and why?
	2. What happens to the variable when both the child and parent change the value? What do you think about it.
2. Write a C program using `fork()`. Let the child process prints 'hello!' and the parent process prints 'goodbye!'. Try to ensure that the child process always prints first.
3. Read the program, `fork-and-exec.c`, and complete it.
4. Write a program using `wait()` to wait for the child process. What does wait() return? What happens if you use wait() in the child.

## References

- UNIX system manuals
- W. Richard Stevens, Stephen A. Rago. Advanced Programming in the Unix Environment, Third Edition. Person Education, Inc.. 2013
- [Operating System: Three Easy Pieces](http://pages.cs.wisc.edu/~remzi/OSTEP/)
