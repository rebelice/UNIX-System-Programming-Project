/**************************************************************************
 * Author	 : RebelIce 杨俊逸
 * Email	 : yangrebelice@gmail.com
 * Github	 : github.com/rebelice
 * ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	/* Variable */
	int x = 2019;
	
	if ((pid = fork()) < 0)
	{
		printf("fork error!\n");
		exit(0);
	}
	else if (pid > 0)
	{
		/* Parent */

		/* TODO: Change value here */

		printf("Parent's value: %d\n", x);
	}
	else if (pid == 0)
	{
		/* Child */

		/* TODO: Change value here */

		printf("Child's value: %d\n", x);
	}
	return 0;
}
