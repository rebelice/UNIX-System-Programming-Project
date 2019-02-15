# File I/O

Designed by Junyi Yang(yangrebelice@gmail.com)

## Introduction

In this lab, we'll know some functions available for file I/O.
We only list the names of the functions which you may need, in order to make you know how to use the UNIX manuals and the search engine.

Be Clear that you only need to know how to use them when you really need to do so.(In our TODO, for example) Now you only need to know what they can do.

## Functions

- open
- creat
- close
- lseek
- read
- write
- sync
- dup, dup2

## Useful

Followings are some useful website. Your UNIX system manual is also useful.
- [Stack Overflow](https://stackoverflow.com)
- [Google](https://www.google.com)
- [Bing](https://www.bing.com)

Usually, you need to seek help from those websites in English.

## **TODO**

1. Write a program that opens a file using `open()` system call and then calls `fork()` to create a new process. What happens to the file's offset in parent process when you change the file's offset in child process? Explain it.
	- You can use `write` or `lseek` to change the file's offset.
	- You may use `lseek` to view current offset.
	- You may use `wait` to guarantee synchronization, which means letting child process change the file's offset first.
2. Write a program that creates a child process, and connects the standard output of parent process to the standard input of child process. Write some messages to the standard output in the parent process, and read them in the child process. Followings are the functions you may need.
	- dup2
	- pipe
	- read
	- write
3. Write a program that creates two children, and connects the standard output of one to the standard input of the other.

## References
- UNIX system manuals
- W. Richard Stevens, Stephen A. Rago. Advanced Programming in the Unix Environment, Third Edition. Person Education, Inc.. 2013
- [Operating System: Three Easy Pieces](http://pages.cs.wisc.edu/~remzi/OSTEP/)
