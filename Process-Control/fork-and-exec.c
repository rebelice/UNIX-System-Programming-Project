/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* We have implemented execl(). 
 * You need to implement the other five */

pid_t pid;
char *arg[4];

void use_execl()
{
	if ((pid = fork()) < 0)
	{
		printf("Fork error!\n");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("exec by execl() function:\n");
		execl(arg[0], arg[1], arg[2], arg[3], arg[4]);
		exit(0);
	}
}

void use_execlp()
{
	if ((pid = fork()) < 0)
	{
		printf("Fork error!\n");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("exec by execlp() function:\n");
		
		/*TODO: use execlp() function */

		exit(0);
	}
}

void use_execle(char *env[])
{
	/* Use "env" like execle(a, b, c, ... , env); */
	if ((pid = fork()) < 0)
	{
		printf("Fork error!\n");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("exec by execle() function:\n");

		/*TODO: use execle() function */
		
		exit(0);
	}
}

void use_execv()
{
	if ((pid = fork()) < 0)
	{
		printf("Fork error!\n");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("exec by execv() function:\n");

		/*TODO: use execv() function */

		exit(0);
	}
}

void use_execvp()
{
	if ((pid = fork()) < 0)
	{
		printf("Fork error!\n");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("exec by execvp() function:\n");

		/*TODO: use execvp() function */

		exit(0);
	}
}

void use_execvpe(char *env[])
{
	/* Use "env" like execvpe(a, b, c, ... , env); */
	if ((pid = fork()) < 0)
	{
		printf("Fork error!\n");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("exec by execvpe() function:\n");

		/*TODO: use execvpe() function */

		exit(0);
	}
}

int main(int argc, char *argv[], char *env[])
{
	/* Get the pointer of this string. 
	 * strdup(3) for more details.*/
	arg[0] = strdup("/bin/ls");
	arg[1] = strdup("ls");
	arg[2] = strdup("-al");
	arg[3] = strdup(".");
	arg[4] = (void *)NULL;

	/* Implemented */
	use_execl();
	wait(NULL);

	/* Implement the other five */
	use_execlp();
	wait(NULL);

	use_execle(env);
	wait(NULL);

	use_execv();
	wait(NULL);

	use_execvp();
	wait(NULL);

	use_execvpe(env);
	wait(NULL);

	return 0;
}
