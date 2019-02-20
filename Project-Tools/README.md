# Project Tools

Designed by Junyi Yang(yangrebelice@gmail.com)

## Introduction

In this lab, we'll introduce some useful tools. You can skip some steps if you already know about these.

## Linux

We recommend using `Ubuntu`/`Debian`. All commands are based on them.

## Search Engines

- [Google](https://www.google.com)
- [Bing](https://bing.com)

## UNIX System Manuals

Use 
```
sudo apt-get install manpages-de  manpages-de-dev  manpages-dev glibc-doc manpages-posix-dev manpages-posix
```
to download UNIX System Manuals to your computer.

## Command-Line Compile and GCC

**If you already know `Command-Line Compile` and `GCC`, you can skip this step.**

You can use any editors(vim, emacs, gedit, vscode, etc.) to write codes, but you need to Command-Line Compile your C progam in the terminals. Also, you can choose any shell you like. Now open your terminal and follow me.

1. Make sure you have GNU C Compiler(gcc). You can use `gcc --version` to determine that.
	- If not, you can use `sudo apt-get install gcc` to install it.
	- If you fail, ask for help by using search engines.
2. Write some simple C codes, just like `hello-world.c`.
3. Use `gcc hello-world.c -o hello-world` to compile you program.
	- There are some useful flags that you may need in the future. Make sure you know what they mean. If not, please get help from `google.com` or `bing.com`.
	- -o
	- -g
	- -c
	- -S
	- -O0 -O1 -O2 -O3
	- -Wall
	- -Werror
4. Now you can use `./hello-world` to run it.
