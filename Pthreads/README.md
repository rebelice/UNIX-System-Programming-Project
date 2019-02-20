# Pthreads

Designed by Junyi Yang(yangrebelice@gmail.com)

## Introduction

In this lab, we'll see the POSIX.1-2001 threads interfaces, also known as `pthreads` for `POSIX threads`.
Here I assume that you know the threads, otherwise you need to read our [textbook](http://pages.cs.wisc.edu/~remzi/OSTEP/).

We'll briefly introduce `pthreads`, you need to see the UNIX system manuals for details. Search engines can also help you.

## Thread Identification

```
	#include <pthread.h>

	/* Compare two thread IDs */
	int pthread_equal(pthread_t tid1, pthread_t tid2);

	/* Obtain thread ID */
	pthread_t pthread_self(void);
```

## Thread Creation and Termination

### Thread Creation

```
	#include <pthread.h>

	int pthread_create(pthread_t *thread,
						const pthread_attr_t *attr,
						void *(*start_routine)(void *),
						void *arg);
```

- Return 0 if OK, error number on failure.
- The memory location pointed to by `thread` is set to the thread ID.
- The `attr` argument is used to customize various thread attributes.
- The new thread starts running at the address of the `start_toutine`.
- The `arg` argument is the parameter of `start_toutine`.

### Thread Termination

A single thread can exit in following three ways.
- Return from the start routine. The return value is the thread's exit code.
- The thread can be canceled by another thread in the same process.
	```
	#include <pthread.h>

	int pthread_cancel(pthread_t thread);
	```
- The thread can call `pthread_exit`.

	```
	#include <pthread.h>

	void pthread_exit(void *retval);
	```

	- The `retval` argument is a typeless pointer which is available to other threads in the process by calling the `pthread_join` function. We'll talk about `pthread_join` later.

**Example**: We have provided a sample program, `CreateAndExit.c`. Use `gcc CreateAndExit.c -pthread -o CreateAndExit` to complie it.

## Thread Joining and Detaching

```
#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);

int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
```

We can use `pthread_join` to wait for the thread to terminate.
In order to achieve this goal, you need to use `pthread_attr_init` and `pthread_attr_setdetachstate`.

See UNIX system manuals and [textbook](http://http://pages.cs.wisc.edu/~remzi/OSTEP/) for details.

**Example**: We have provided a sample program, `Joining.c`. Use `gcc Joining.c -pthread -o Joining` to compile it.

## Mutex 

```
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_trylock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);

int pthread_mutex_destroy(pthread_mutex_t *mutex);
```
See UNIX system manuals and [textbook](http://http://pages.cs.wisc.edu/~remzi/OSTEP/) for details.

## Condition Variables

```
#include <pthread.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int pthread_cond_init(pthread_cond_t *cond, pthread_condattr_t *cond_attr);

int pthread_cond_signal(pthread_cond_t *cond);

int pthread_cond_broadcast(pthread_cond_t *cond);

int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);

int pthread_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime);

int pthread_cond_destroy(pthread_cond_t *cond);
```

See UNIX system manuals and [textbook](http://http://pages.cs.wisc.edu/~remzi/OSTEP/) for details.

## **TODO**

- See `CreateAndExit.c` and run it.
- See `Joining.c` and run it.
- Read the [textbook](http://http://pages.cs.wisc.edu/~remzi/OSTEP/), Chapter 26-31.
- Write a program that creates three threads and read an integer `a` which is between 1 and 9 as input. Let the thread one calculate $a!$. Let the thread two calculate $a^a$. And let the thread three calculate the sum of the two, which means $a!+a^a$. Yon need to let the thread three use the results of the thread one and two.

## References

- UNIX system manuals
- W. Richard Stevens, Stephen A. Rago. Advanced Programming in the Unix Environment, Third Edition. Person Education, Inc.. 2013
- [Operating System: Three Easy Pieces](http://pages.cs.wisc.edu/~remzi/OSTEP/)
